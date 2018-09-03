
 #include <iostream>
 using namespace std;
 typedef unsigned long long ull;

 ull modpower(ull base, ull exponent, ull modulus) {
    if (exponent == 0) {
        return 1 % modulus;
    }
    ull result = modpower(base, exponent / 2, modulus);
    result = (result % modulus * result % modulus) % modulus;
    return (exponent % 2 == 0) ? result : (base % modulus * result % modulus ) % modulus;
 }

 int main() {

 }