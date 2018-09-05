
#include <cmath>
#include <iostream>

using namespace std;
typedef unsigned long long ull; 
 
 ull modpower(ull base, ull exponent, ull modulus) {
    if (exponent == 0) return 1;
    ull result = modpower(base, exponent / 2, modulus);
    result = (result * result) % modulus;
    return (exponent % 2 == 0) ? result : (base * result) % modulus;
 }

bool isPrime(ull num) {
    if (num < 2) return false;
    for (ull i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}
