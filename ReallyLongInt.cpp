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
    return (isNeg == false && other.isNeg == false) ? absGreater(other) 
        : (isNeg == true && other.isNeg == true) ? !absGreater(other) 
        : (isNeg == false) ? true : false; 
}


//Unsigned Addition
ReallyLongInt ReallyLongInt::absAdd(const ReallyLongInt& other) const {
    unsigned maxLen = absGreater(other) ? numDigits + 1 : other.numDigits + 1;
    unsigned* result = new unsigned[maxLen];
    unsigned carry = 0;

    for (int i = maxLen - 1; i >= 0; i--) {
        result[i] = (maxLen - i > numDigits) ? 0 : digits[numDigits + i - maxLen];
        result[i] += (maxLen - i > other.numDigits) ? 0 : other.digits[other.numDigits + i - maxLen];
        result[i] += carry;
        carry = result[i] / 10;
        result[i] = result[i] % 10;
    }
    removeLeadingZeros(result, maxLen);
    return ReallyLongInt(result, maxLen, false);
}

ReallyLongInt ReallyLongInt::add(const ReallyLongInt& other) const {
    return absAdd(other);
}

//Unsigned Subtraction
ReallyLongInt ReallyLongInt::absSub(const ReallyLongInt& other) const {
    unsigned maxLen = absGreater(other) ? numDigits : other.numDigits;
    unsigned* result = new unsigned[maxLen];
    unsigned borrow = 0;

    if (absGreater(other)) {
        for (int i = 1; i <= maxLen; i++) {
            result[maxLen - i] = digits[numDigits - i] + 10;
            result[maxLen - i] -= (i > other.numDigits) ? 0 : other.digits[other.numDigits - i];
            result[maxLen - i] -= borrow;
            borrow = (result[maxLen - i] < 10) ? 1 : 0;
            result[maxLen - i] = result[maxLen - i] % 10;
        }
        removeLeadingZeros(result, maxLen);
        return ReallyLongInt(result, maxLen, false);
    } else {
        for (int i = 1; i <= maxLen; i++) {
            result[maxLen - i] = other.digits[other.numDigits - i] + 10;
            result[maxLen - i] -= (i > numDigits) ? 0 : digits[numDigits - i];
            result[maxLen - i] -= borrow;
            borrow = (result[maxLen - i] < 10) ? 1 : 0;
            result[maxLen - i] = result[maxLen - i] % 10;
        }
        removeLeadingZeros(result, maxLen);
        return ReallyLongInt(result, maxLen, true);
    }
}

ReallyLongInt ReallyLongInt::sub(const ReallyLongInt& other) const {
    return absSub(other);
}

/*--------------------------
----------Test Area---------
---------------------------*/
//Overloading output stream
//ref: https://msdn.microsoft.com/en-us/library/1z2f6c2k.aspx
// ostream& operator<<(ostream& os, const ReallyLongInt& i) {  
//     os << i.toString();  
//     return os;  
// }  


// unsigned ReallyLongInt::getNumDigits() {
//     return numDigits;
// }

// bool ReallyLongInt::getIsNeg() {
//     return isNeg;
// }

// int main(int argc, char const *argv[])
// {
//     ReallyLongInt* a = new ReallyLongInt(1231);
//     ReallyLongInt* b = new ReallyLongInt("42");


//     ReallyLongInt c = a->sub(*b);
//     ReallyLongInt d = b->sub(*a);
//     cout << c.toString() << endl;
//     cout << d.toString() << endl;

// }
