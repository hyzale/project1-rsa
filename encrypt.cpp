
#include <iostream>
#include <fstream>
using namespace std;
typedef unsigned long long ull; 
 
 ull modpower(ull base, ull exponent, ull modulus) {
    if (exponent == 0) return 1 % modulus;
    ull result = modpower(base, exponent / 2, modulus);
    result = (result * result) % modulus;
    return (exponent % 2 == 0) ? result : (base * result) % modulus;
 }

 int main() {
    ull e; ull n; char x;
    ifstream encryptFile("public.txt");
    ifstream fin("plaintext.txt");
    ofstream fout("encrpyted.txt");
    encryptFile >> e >> n;
    while(fin.get(x)){
        fout << modpower(x, e, n) << endl;
    } 
 }