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
 int main(int argc, char *argv[]) {
    if (argc != 4) {
        cout << "Wrong Number of Command Line Arguments Passed";
        return 0;
    }    
    ull d; ull n; int y;
    ifstream decryptFile(argv[1]);
    ifstream fin(argv[2]);
    ofstream fout(argv[3]);
    decryptFile >> d >> n;
    fin >> y;
    while(!fin.eof()){
        fout << (char) modpower(y, d, n);
        fin >> y;
    }
 }