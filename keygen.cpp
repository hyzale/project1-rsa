
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "numberTheory.hpp"

typedef unsigned long long ull; 
typedef long long ll;

using namespace std;

int main (int argc, char *argv[]) {
    
    if (argc != 5) {
        cout << "Wrong Number of Command Line Arguments Passed.";
        return 0;
    }

    ll p = atoi(argv[1]);
    ll q = atoi(argv[2]);

    if (!isPrime(p) || !isPrime(q)) { 
        cout << "The provided numbers are not all prime.";
        return 1;
    }
    
    ull n = p * q;
    
    if (n <= 256) {
        cout << "Warning: generated key cannot encrtpt ASCII values" << endl;
    }

    ull t = (p - 1) * (q - 1);
    ull e = 2; ll x; ll y; ll d;

    for (int i = 2; i < t; i++) {
        if (extendEuclid(e, t, &d, &y) == 1){
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
