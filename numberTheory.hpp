
 #ifndef NUMBERTHEORY_H
 #define NUMBERTHEORY_H

template <class X>
X modPower(const X& base, const X& exponent, const X& modulus);

template <class X>
bool isPrime(const X& num);

template <class X>
X extendEuclid(const X& a, const X& b, X* x, X* y);

#include "numberTheory.tpp"

#endif