#include <iostream>
#include <string>
#include "reallyLongInt.hpp"

using namespace std;
typedef unsigned long long ull; 
typedef long long ll;


unsigned* rlIntMake(const string& numStr, unsigned& numDigits) {
    numDigits = numStr.size();
    unsigned* numArr = new unsigned[numDigits];
    for (int i = 0; i < numDigits; i++) {
        numArr[i] = numStr[i] - 48;
    }
    rlIntRemoveLeadingZeros(numArr, numDigits);
    return numArr;
}

string rlIntToString(const unsigned* x, unsigned xSize) {
    string numStr;
    for (int i = 0; i < xSize; i++) {
        numStr += to_string(x[i]);
    }
    return numStr;
}

void rlIntRemoveLeadingZeros(unsigned* x, unsigned& xSize) {
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

    // if (x[0] == 0 && xSize != 1) {
    //     for (int i = 0; i < xSize - 1; i++) {
    //         x[i] = x[i + 1];
    //     }
    //     xSize --;
    //     rlIntRemoveLeadingZeros(x, xSize);

    // }

}

bool rlIntEqual(const unsigned* x, unsigned xSize, const unsigned* y, unsigned ySize) {
    if (xSize != ySize) {
        return false;
    }
    
    for (int i = 0; i < xSize; i++) {
        if (x[i] != y[i]) {
            return false;
        }
    }
    return true;

}

bool rlIntGreater(const unsigned* x, unsigned xSize, const unsigned* y, unsigned ySize) {
    
    if (xSize > ySize) {
        return true;
    } 

    if (xSize < ySize) {
        return false;
    }
    
    for (int i = 0; i < xSize; i++) {
        if (x[i] > y[i]) {
            return true;
        }
    }
    
    return false; 
}
/*
int main(int argc, char const *argv[])
{
    unsigned xSize;
    unsigned* a = rlIntMake("000000000", xSize);
    cout << a[0] << endl;
    cout << xSize << endl;
}
*/
