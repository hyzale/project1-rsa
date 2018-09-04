
#include <iostream>
#include <fstream>
#include "numberTheory.hpp"

using namespace std;
typedef unsigned long long ull; 
 

 int main(int argc, char *argv[]) {
    if (argc != 4) {
        cout << "Wrong Number of Command Line Arguments Passed";
        return 0;
    }
    ifstream encryptFile(argv[1]);
    ifstream fin(argv[2]);
    ofstream fout(argv[3]);
    ull e; ull n; char x; 
    //bad variable name copy from spec, e is exponent in modpower function and n is mod
    encryptFile >> e >> n;
    while(fin.get(x)){
        fout << modpower(x, e, n) << endl;
    } 
 }