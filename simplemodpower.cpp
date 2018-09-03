 
 #include <iostream>
 using namespace std;
 typedef unsigned long long ull;

 ull power(ull base, ull exponent) {
    ull result = 1;
    for (int i = 1; i <= exponent; i++) 
    {
        result = result * base;
    }
    return result;
 }

 ull modpower(ull base, ull exponent, ull modulus) {
    return power(base, exponent) % modulus;
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
