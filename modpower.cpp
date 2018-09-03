
 #include <iostream>
 using namespace std;
 typedef unsigned long long ull;
 
 ull modpower(ull base, ull exponent, ull modulus) {
    if (exponent == 0) {
        return 1 % modulus;
    }
    ull result = modpower(base, exponent / 2, modulus);
    result = (result * result) % modulus;
    return (exponent % 2 == 0) ? result : (base * result) % modulus;
 }

 int main() {
    cout << modpower(2, 2, 3) << endl;
    cout << modpower(2, 3, 3) << endl;
    cout << modpower(12, 12, 123) << endl;
    cout << modpower(10, 19, 1019) << endl;
    cout << modpower(12345, 1234567, 123) << endl;
    cout << modpower(12345, 1234567, 123456789) << endl;
    cout << modpower(12345, 123456789, 12345) << endl;
    cout << modpower(12345, 123456789, 1234567891011) << endl;
 }
