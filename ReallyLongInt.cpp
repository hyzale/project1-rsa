#include <string>
#include <iostream>
#include <cmath>

#include "ReallyLongInt.hpp"

using namespace std;

//Defult Constructor to represent 0
ReallyLongInt::ReallyLongInt() {
    isNeg = false;
    numDigits = 1;
    unsigned* numArr = new unsigned[1];
    numArr[0] = 0;
    digits = numArr;
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
    if (num == 0) {
        isNeg = false;
        numDigits = 1;
        unsigned* numArr = new unsigned[1];
        numArr[0] = 0;
        digits = numArr;
    } else {
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
}

//Copy Constructor
ReallyLongInt::ReallyLongInt(const ReallyLongInt& other) {
    this->numDigits = other.numDigits;
    this->isNeg = other.isNeg;
    unsigned* deepCopy = new unsigned[numDigits];
    for (int i = 0; i < numDigits; i++) {
        deepCopy[i] = other.digits[i];
    }
    digits = deepCopy;
    //memcpy()

}

//Private Constructor
ReallyLongInt::ReallyLongInt(unsigned* digitsArr, unsigned arrSize, bool isNeg) {
    removeLeadingZeros(digitsArr, arrSize);
    this->digits = digitsArr;
    this->numDigits = arrSize;
    this->isNeg = isNeg;
    if (digits[0] == 0) {this->isNeg = false;}
}

//Comparison operators
bool ReallyLongInt::equal(const ReallyLongInt& other) const{
    if (numDigits != other.numDigits || isNeg != other.isNeg) {
        return false;
    }
    for (int i = 0; i < numDigits; i++) {
        if (digits[i] != other.digits[i]) {
            return false;
        }
    }
    return true;
}

bool ReallyLongInt::absGreater(const ReallyLongInt& other) const {
    if (numDigits > other.numDigits) {
        return true;
    } 

    if (numDigits < other.numDigits) {
        return false;
    }
    
    for (int i = 0; i < numDigits; i++) {
        if (digits[i] > other.digits[i]) {
            return true;
        }
    }
    return false;   
}

bool ReallyLongInt::greater(const ReallyLongInt& other) const {
    return (isNeg == other.isNeg) ? absGreater(other) : (isNeg == true) ? false : true; 
}


//Unsigned Addition
ReallyLongInt ReallyLongInt::absAdd(const ReallyLongInt& other) const {
    unsigned carry = 0;
    unsigned maxLen = numDigits;
    if (other.numDigits > maxLen) {
        maxLen = other.numDigits;
    }
    unsigned* resDigits = new unsigned[maxLen + 1];
    for (int i = maxLen - 1; i >= 0; i--) {
        resDigits[i + 1] = (i < numDigits) ? digits[i] : 0;
        resDigits[i + 1] += (i < other.numDigits) ? other.digits[i] : 0;
        resDigits[i + 1] += carry;
        carry = resDigits[i + 1] / 10;
        resDigits[i + 1] = resDigits[i + 1] % 10;
    }
    resDigits[0] = carry;
    if (carry == 0) {
        unsigned* resDigitsCut = new unsigned[maxLen];
        for (int i = maxLen - 1; i >= 0; i--) {
            resDigitsCut[i] = resDigits[i + 1];
        }
        delete[] resDigits;
        return ReallyLongInt(resDigitsCut, maxLen, false);
    } else {
        return ReallyLongInt(resDigits, maxLen + 1, false);
    }
}

//Unsigned Subtraction




/*--------------------------
----------Test Area---------
---------------------------
//Overloading output stream
//ref: https://msdn.microsoft.com/en-us/library/1z2f6c2k.aspx
ostream& operator<<(ostream& os, const ReallyLongInt& i) {  
    os << i.toString();  
    return os;  
}  


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

    ReallyLongInt* d = new ReallyLongInt("002001");


    ReallyLongInt b = ReallyLongInt("99");
    ReallyLongInt c = ReallyLongInt("99");
    ReallyLongInt d = b.absAdd(c);
    cout << d;

}*/