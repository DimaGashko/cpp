#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin("input.txt");
	ofstream fout("output.txt");
    
    string str, rev, tmp;
    
    while (fin >> tmp) {
        str += tmp;
    }
    
    rev = str;
    reverse(rev.begin(), rev.end());
    
    fout << (str == rev ? "YES" : "NO");
    
    fin.close();
	fout.close();
    return 0;
}