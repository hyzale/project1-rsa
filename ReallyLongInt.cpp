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
    return (!isNeg && !other.isNeg) ? absGreater(other) 
        : (isNeg && other.isNeg) ? !absGreater(other) 
        : (!isNeg && other.isNeg) ? true : false; 
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
    if (!this->isNeg && !other.isNeg) {
        return absAdd(other);
    } else if (this->isNeg && other.isNeg) {
        return -absAdd(other);
    } else if (this-> isNeg && this->absGreater(other)) {
        return -absSub(other);
    } else {
        return absSub(other);
    }
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
    if (!this->isNeg && !other.isNeg) {
        return absSub(other);
    } else if (this->isNeg && !other.isNeg) {
        return -absAdd(other);
    } else if (!this->isNeg && other.isNeg) {
        return absAdd(other);
    } else {
        return -absSub(other);
    }
}

//Overloading output stream
ostream& operator<<(ostream& out, const ReallyLongInt& x) {  
    out << x.toString();  
    return out;  
}     

//Overloading assignment
void ReallyLongInt::swap(ReallyLongInt other) {
    std::swap(this->digits, other.digits);
    std::swap(this->numDigits, other.numDigits);
    std::swap(this->isNeg, other.isNeg);
}

ReallyLongInt& ReallyLongInt::operator=(const ReallyLongInt& other) {
    this->swap(other);
    return *this;
}

//Overloading comparison
bool operator==(const ReallyLongInt& x, const ReallyLongInt& y){
    return x.equal(y);
}

bool operator!=(const ReallyLongInt& x, const ReallyLongInt& y) {
    return !x.equal(y);
}

bool operator>(const ReallyLongInt& x, const ReallyLongInt& y) {
    return x.greater(y);
}

bool operator<(const ReallyLongInt& x, const ReallyLongInt& y) {
    return y.greater(x);
}

bool operator>=(const ReallyLongInt& x, const ReallyLongInt& y) {
    return x.greater(y) || x.equal(y);
}
bool operator<=(const ReallyLongInt& x, const ReallyLongInt& y) {
    return y.greater(x) || x.equal(y);
}

//Addition and Subtraction
void ReallyLongInt::flipSign() {
    isNeg = (digits[0]== 0) ? false : !isNeg;
}

ReallyLongInt ReallyLongInt::operator-() const {
    ReallyLongInt* a = new ReallyLongInt(*this);
    a->flipSign();
    return *a;
}

ReallyLongInt operator+(const ReallyLongInt& x, const ReallyLongInt& y) {
    return x.add(y);
}

ReallyLongInt operator-(const ReallyLongInt& x, const ReallyLongInt& y) {
    return x.sub(y);
}

ReallyLongInt& ReallyLongInt::operator+=(const ReallyLongInt& other) {
    *this = *this + other;
    return *this;

}

ReallyLongInt& ReallyLongInt::operator-=(const ReallyLongInt& other) {
    *this = *this - other;    
    return *this;
}

ReallyLongInt& ReallyLongInt::operator++() {
    *this += ReallyLongInt(1);
    return *this;
}

ReallyLongInt& ReallyLongInt::operator--() {
    *this -= ReallyLongInt(1);
    return *this;
}
ReallyLongInt ReallyLongInt::operator++(int dummy) {
    ReallyLongInt* a = new ReallyLongInt(*this);
    *this += ReallyLongInt(1);
    return *a;
}

ReallyLongInt ReallyLongInt::operator--(int dummy) {
    ReallyLongInt* a = new ReallyLongInt(*this);
    *this -= ReallyLongInt(1);
    return *a;
}

ReallyLongInt ReallyLongInt::absMult(const ReallyLongInt& other) const {
    unsigned maxLen = numDigits + other.numDigits;
    unsigned* result = new unsigned[maxLen];

    for (int i = 0; i < numDigits; i++) {
        unsigned carry = 0;
        for (int j = 0; j <= other.numDigits; j++) {
            int temp = digits[i] * other.digits[j] + carry;
            carry = temp / 10;
            temp = (result[i + j] += temp % 10);
            result[i + j] = temp % 10;
            carry += temp / 10;

        }
    }
    removeLeadingZeros(result, maxLen);
    return ReallyLongInt(result, maxLen, false);
}

ReallyLongInt ReallyLongInt::Mult(const ReallyLongInt& other) const {
    return (this->isNeg == other.isNeg) ? absMult(other) : -absMult(other);
}

ReallyLongInt operator*(const ReallyLongInt& x, const ReallyLongInt& y){
    return x.Mult(y);
}
ReallyLongInt ReallyLongInt::operator*=(const ReallyLongInt& other) {
    *this = *this * other;
    return *this;
}



/*--------------------------
----------Test Area---------
---------------------------*/


int main(int argc, char const *argv[])
{
    ReallyLongInt x(56);
    ReallyLongInt y(34);
    cout << x.Mult(y) << endl;
}
