#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	long long sum = 0;
   int tmp = 0;
   
   while (fin >> tmp) {
      sum += tmp;
   }
   
   fout << sum;
      
	fin.close();
	fout.close();
	return 0;
}