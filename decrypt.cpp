
#include <iostream>
#include <fstream>
#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"

using namespace std;
 

 int main(int argc, char *argv[]) {
     
    if (argc != 4) {
        cout << "Wrong Number of Command Line Arguments Passed";
        return 0;
    }    
    
    ifstream decryptFile(argv[1]);
    string exponent; string mod; 
    decryptFile >> exponent >> mod;
    ReallyLongInt d(exponent); ReallyLongInt n(mod);
    
    ifstream fin(argv[2]);
    ofstream fout(argv[3]);
    ReallyLongInt y;
    string a;
    
    fin >> a;
    y = ReallyLongInt(a);

    while(!fin.eof()){
        ReallyLongInt result = modPower(y, d, n);
        long long res = result.toLongLong();
        fout << (char) res;
        fin >> a;
        y = ReallyLongInt(a);
    }
 }
