#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
	string s;
	int i, j;

	getline(fin, s);
	fin >> i >> j;
	i--;

	reverse(s.begin() + i, s.begin() + j);

	fout << s;

	fin.close();
	fout.close();
	return 0;
}