
 #ifndef modpower_h
 #define modpower_h
 
typedef unsigned long long ull; 
typedef long long ll;


ull modpower(ull base, ull exponent, ull modulus);

bool isPrime(ull num);

ull extendEuclid(ull a, ull b, ll *x, ll *y);


#endif