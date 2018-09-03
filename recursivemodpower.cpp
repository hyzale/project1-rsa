
 #include <iostream>
 using namespace std;
 typedef unsigned long long ull;

 
 ull power(ull base, ull exponent) {
    if (exponent == 1) {
        return base;
    }
    else
    {
        ull result = power(base, exponent / 2);
        if (exponent % 2 == 0) {
            return result * result;
        }
        else {
            return result * result * base;
        }
    }
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
