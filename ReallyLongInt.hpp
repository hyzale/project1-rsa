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
public:
    ReallyLongInt();
    ReallyLongInt(const string& numStr);
    ~ReallyLongInt();
    string toString() const;
    ReallyLongInt(long long num);
    ReallyLongInt(const ReallyLongInt& other);
    ReallyLongInt absAdd(const ReallyLongInt& other) const;
    ReallyLongInt absSub(const ReallyLongInt& other) const;


/*--------Test Method--------*/
    unsigned getNumDigits();
    bool getIsNeg();
};


#endif