#ifndef rlIntRemoveLeadingZeros_h
#define rlIntRemoveLeadingZeros_h
#include <string>
using namespace std;

void rlIntRemoveLeadingZeros(unsigned* x, unsigned& xSize);

unsigned* rlIntMake(const string& numStr, unsigned& numDigits);

string rlIntToString(const unsigned* x, unsigned xSize);

bool rlIntEqual(const unsigned* x, unsigned xSize, const unsigned* y, unsigned ySize);

bool rlIntGreater(const unsigned* x, unsigned xSize, const unsigned* y, unsigned ySize);

#endif