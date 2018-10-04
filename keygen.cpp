
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"

using namespace std;

int main (int argc, char *argv[]) {
    
    if (argc != 5) {
        cout << "Wrong Number of Command Line Arguments Passed.";
        return 0;
    }

    ReallyLongInt p(argv[1]);
    ReallyLongInt q(argv[2]);

    if (p > 100000 || q > 100000) {
        cout << "Numbers are too large and the primality not being verified." << endl;
        return 1;
    } 

    if (!isPrime(p) || !isPrime(q)) { 
        cout << "The provided numbers are not all prime.";
        return 2;
    }
    
    ReallyLongInt n(p * q);
    
    if (n <= 256) {
        cout << "Warning: generated key cannot encrtpt ASCII values" << endl;
    }

    ReallyLongInt t = (p - 1) * (q - 1);
    ReallyLongInt e = 2; ReallyLongInt x; ReallyLongInt y; ReallyLongInt d;

    for (ReallyLongInt i = 2; i < t; i++) {
        if (extendEuclid(i, t, &x, &y) == 1){
            e = i;
            break;
        }
    }

    (x < 0) ? d = x + t : d = x;
    
    ofstream publicKey(argv[3]);
    ofstream privateKey(argv[4]);
    
    publicKey << e << " " << n << endl;
    privateKey << d << " " << n << endl;

}
