#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int all = 0, tmp;
	for (int i = 0; i < 31; i++) {
		fin >> tmp;
		all += tmp;
	}

	fout << all / 27;

	fin.close();
	fout.close();
	return 0;
}