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

//overloading output stream
// ref: https://msdn.microsoft.com/en-us/library/1z2f6c2k.aspx
ostream& operator<<(ostream& os, const ReallyLongInt& i) {  
    os << i.toString();  
    return os;  
}  

//Constructor from numbers
ReallyLongInt::ReallyLongInt(long long num) {

}

//Copy Constructor

ReallyLongInt::ReallyLongInt(const ReallyLongInt& other) {
    
}

//Private Constructor

ReallyLongInt::ReallyLongInt(unsigned* digitsArr, unsigned arrSize, bool isNeg) {
    this->digits = digitsArr;
    this->numDigits = arrSize;
    this->isNeg = isNeg;
}

ReallyLongInt ReallyLongInt::absAdd(const ReallyLongInt& other) const {
    unsigned carry = 0;
    unsigned maxLen = numDigits;
    if (other.numDigits > maxLen) {
        maxLen = other.numDigits;
    }
    unsigned * res_digits = new unsigned[maxLen + 1];
    // +1 for possible inc
    for (int i = maxLen - 1; i >= 0; i--) {
        res_digits[i + 1] = digits[i] + other.digits[i] + carry;
        carry = res_digits[i + 1] / 10;
        res_digits[i + 1] = res_digits[i + 1] % 10;
    }
    res_digits[0] = carry;
    if (carry == 0) {
        unsigned * res_digits_cut = new unsigned[maxLen];
        for (int i = maxLen - 1; i >= 0; i--) {
            res_digits_cut[i] = res_digits[i + 1];
        }
        delete[] res_digits;
        return ReallyLongInt(res_digits_cut, maxLen, false);
    } else {
        return ReallyLongInt(res_digits, maxLen + 1, false);
    }
}



ReallyLongInt ReallyLongInt::absAdd(const ReallyLongInt& other) const {
    unsigned carry = 0;
    unsigned maxLen = numDigits;
    if (other.numDigits > maxLen) {
        maxLen = other.numDigits;
    }
    unsigned * res_digits = new unsigned[maxLen + 1];
    // +1 for possible inc
    for (int i = maxLen - 1; i >= 0; i--) {
        res_digits[i + 1] = digits[i] + other.digits[i] + carry;
        carry = res_digits[i + 1] / 10;
        res_digits[i + 1] = res_digits[i + 1] % 10;
    }
    res_digits[0] = carry;
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
    ReallyLongInt* a = new ReallyLongInt("002001");


    ReallyLongInt b = ReallyLongInt("99");
    ReallyLongInt c = ReallyLongInt("99");
    ReallyLongInt d = b.absAdd(c);
    cout << d;

}