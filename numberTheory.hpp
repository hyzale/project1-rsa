
 #ifndef MODPOWER_H
 #define MODPOWER_H
 
typedef unsigned long long ull; 
typedef long long ll;


ull modPower(ull base, ull exponent, ull modulus);

bool isPrime(ull num);

ull extendEuclid(ull a, ull b, ll* px, ll* py);


#endif