#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("input.txt");
	ofstream fout("output.txt");
    
    long long r = 0;
    fin >> r;
    
    int tmp;
    char o;
    
    while (fin >> o >> tmp) {
        if (o == '+') r += tmp;
        else r -= tmp;
    }
    
    fout << r;
    
    fin.close();
	fout.close();
    return 0;
}