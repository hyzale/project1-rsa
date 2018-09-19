#include <string>
#include <iostream>
#include <cmath>

#include "ReallyLongInt.hpp"

using namespace std;

//Defult Constructor to represent 0
ReallyLongInt::ReallyLongInt() {
    isNeg = false;
    digits = 0;
    numDigits = 1;
}


//Private method to remove leading zeroes
void ReallyLongInt::removeLeadingZeros(unsigned* x, unsigned& xSize) const {
    int count = -1;
    for (int i = 0; i < xSize; i++) {
        if (x[i] != 0) {
            count = i;
            break;
        }
    }
   
    if (count == -1) {
        xSize = 1;
        x[0] = 0;
    } else {
        for (int i = 0; i < xSize - count; i++) {
            x[i] = x[count + i];
        }
        xSize -= count;
    }   

/*change to iterative method after comment from checkpoint 2
change to iterative method after comment from checkpoint 2
    if (x[0] == 0 && xSize != 1) {
        for (int i = 0; i < xSize - 1; i++) {
            x[i] = x[i + 1];
        }
        xSize --;
        removeLeadingZeros(x, xSize);

    }    */

}

//String Construstor
ReallyLongInt::ReallyLongInt(const string& numStr) {
    isNeg = (numStr[0] == '-');
    numDigits = numStr.size();
    unsigned* numArr = new unsigned[numDigits];
    
    if (isNeg) {
        for (int i = 0; i < numDigits - 1; i++) {
            numArr[i] = numStr[i + 1] - 48;
        }
        numDigits --;    
    } else {
        for (int i = 0; i < numDigits; i++) {
            numArr[i] = numStr[i] - 48;
        }    
    }
    removeLeadingZeros(numArr, numDigits);
    digits = numArr;
    if (digits[0] == 0) {isNeg = false;}
}

//Destructor
ReallyLongInt::~ReallyLongInt() {
    delete digits;
}

//toString method
string ReallyLongInt::toString() const {
    string numStr;
    if (isNeg) {numStr = "-";}
    for (int i = 0; i < numDigits; i++) {
        numStr += to_string(digits[i]);
    }
    return numStr;
}

//Constructor from numbers
ReallyLongInt::ReallyLongInt(long long num) {
    if (num == 0) {ReallyLongInt();}
    if (num > 0) {isNeg = false;}    
    if (num < 0) {isNeg = true; num = -num;}
    numDigits = log10(num) + 1;
    unsigned* numArr = new unsigned[numDigits];
    
    for (int i = numDigits - 1; i >= 0; i--) {
        numArr[i] = num % 10;
        num /= 10;        
    }
    digits = numArr;
}

//Copy Constructor

ReallyLongInt::ReallyLongInt(const ReallyLongInt& other) {
    numDigits == other.numDigits;
    unsigned* numArr = new unsigned[numDigits];
    
}

//Private Constructor
ReallyLongInt::ReallyLongInt(unsigned* digitsArr, unsigned arrSize, bool isNeg) {
    removeLeadingZeros(digitsArr, arrSize);
    digits = digitsArr;
    numDigits = arrSize;
    isNeg = isNeg;
    if (digits[0] == 0) {isNeg = false;}
}





/*--------------------------
----------Test Area---------
---------------------------*/


unsigned ReallyLongInt::getNumDigits() {
    return numDigits;
}

bool ReallyLongInt::getIsNeg() {
    return isNeg;
}

int main(int argc, char const *argv[])
{
    ReallyLongInt* a = new ReallyLongInt(-2001);
    cout << a->toString() << endl;
    cout << a->getNumDigits() << endl;
    cout << a->getIsNeg() << endl;

}