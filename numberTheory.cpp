
#include <cmath>
#include <iostream>

using namespace std;
typedef unsigned long long ull; 
typedef long long ll;
  
ll x; ll y; 

 ull modPower(ull base, ull exponent, ull modulus) {
    if (exponent == 0) return 1;
    ull result = modPower(base, exponent / 2, modulus);
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


ull extendEuclid(ull a, ull b, ll* px, ll* py) {

    if (b == 0) {
        *px = 1; *py = 0; return a;
    }
    ll x1, y1;
    ull d = extendEuclid(b, a % b, &x1, &y1);
    *px = y1;
    *py = x1 - y1 * (a / b);    

    return d;

}


