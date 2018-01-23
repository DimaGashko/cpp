#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int t = 0, a, b;
   fin >> t;
   
   for (int i = 0; i < t; i++) {
      fin >> a >> b;
      fout << (a + b) << endl;
   }
      
	fin.close();
	fout.close();
	return 0;
}