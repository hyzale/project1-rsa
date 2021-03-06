#ifndef REALLYLONGINT_H
#define REALLYLONGINT_H
#include <string>
#include <cstring>
#include <string.h>

using namespace std;

class ReallyLongInt 
{
private:
    bool isNeg;
    const unsigned* digits;
    unsigned numDigits;

    void removeLeadingZeros(unsigned* x, unsigned& xSize) const;
    ReallyLongInt(unsigned* digitsArr, unsigned arrSize, bool isNeg);
    ReallyLongInt absAdd(const ReallyLongInt& other) const;
    ReallyLongInt absSub(const ReallyLongInt& other) const;
    void swap(ReallyLongInt other);
    void flipSign();
    ReallyLongInt absMult(const ReallyLongInt& other) const;
    void absDiv(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const;
    bool absGreater(const ReallyLongInt& other) const;



public:
    ReallyLongInt();
    ReallyLongInt(const string& numStr);
    ~ReallyLongInt();
    string toString() const;
    ReallyLongInt(long long num);
    ReallyLongInt(const ReallyLongInt& other);
    bool equal(const ReallyLongInt& other) const;
    bool greater(const ReallyLongInt& other) const;
    ReallyLongInt add(const ReallyLongInt& other) const;
    ReallyLongInt sub(const ReallyLongInt& other) const;
    ReallyLongInt& operator=(const ReallyLongInt& other);
    ReallyLongInt operator-() const;
    ReallyLongInt& operator+=(const ReallyLongInt& other);
    ReallyLongInt& operator-=(const ReallyLongInt& other);
    ReallyLongInt& operator++();
    ReallyLongInt& operator--();
    ReallyLongInt operator++(int dummy);
    ReallyLongInt operator--(int dummy);
    ReallyLongInt mult(const ReallyLongInt& other) const;
    ReallyLongInt operator*=(const ReallyLongInt& other);
    void div(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const;
    ReallyLongInt operator/=(const ReallyLongInt& other);
    ReallyLongInt operator%=(const ReallyLongInt& other);
    long long toLongLong() const;
    
/*Test Method*/
    unsigned getNumDigits();
    bool getIsNeg();

};

ostream& operator<<(ostream& out, const ReallyLongInt& x);
ReallyLongInt operator+(const ReallyLongInt& x, const ReallyLongInt& y);
ReallyLongInt operator-(const ReallyLongInt& x, const ReallyLongInt& y);
bool operator==(const ReallyLongInt& x, const ReallyLongInt& y);
bool operator!=(const ReallyLongInt& x, const ReallyLongInt& y);
bool operator>(const ReallyLongInt& x, const ReallyLongInt& y);
bool operator<(const ReallyLongInt& x, const ReallyLongInt& y);
bool operator>=(const ReallyLongInt& x, const ReallyLongInt& y);
bool operator<=(const ReallyLongInt& x, const ReallyLongInt& y);
ReallyLongInt operator*(const ReallyLongInt& x, const ReallyLongInt& y);
ReallyLongInt operator/(const ReallyLongInt& x, const ReallyLongInt& y);
ReallyLongInt operator%(const ReallyLongInt& x, const ReallyLongInt& y);

#endif