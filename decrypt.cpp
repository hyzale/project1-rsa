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