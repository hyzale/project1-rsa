
#include <iostream>
#include <fstream>
#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"

using namespace std;
typedef unsigned long long ull; 
 
 int main(int argc, char *argv[]) {
    if (argc != 4) {
        cout << "Wrong Number of Command Line Arguments Passed";
        return 0;
    }
    
    ifstream encryptFile(argv[1]);
    string exponent; string mod; 
    encryptFile >> exponent >> mod;
    ReallyLongInt e(exponent); ReallyLongInt n(mod);
    
    ifstream fin(argv[2]);
    ofstream fout(argv[3]);
    char x; //x is the character to be encrypted
    
    while(fin.get(x)){
        ReallyLongInt num(x);
        fout << modPower(num, e, n) << endl;
    } 
 }