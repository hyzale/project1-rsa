
#include <cmath>
#include <iostream>

using namespace std;

template <class X>
X modPower(const X& base, const X& exponent, const X& modulus) {
    if (exponent == 0) return 1;
    X result = modPower(base, exponent / 2, modulus);
    result = (result * result) % modulus;
    return (exponent % 2 == 0) ? result : (base * result) % modulus;
 }

template <class X>
bool isPrime(const X& num) {
    if (num < 2) return false;
    for (X i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

template <class X>
X extendEuclid(const X& a, const X& b, X* x, X* y) {

    if (b == 0) {
        *x = 1; *y = 0; return a;
    }
    X x1, y1;
    X d = extendEuclid(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - y1 * (a / b);    

    return d;

}