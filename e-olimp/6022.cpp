#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
	int n, lose = 0;
	string g;
	fin >> n;

	for (int i = 0; i < n; i++) {
		fin >> g;

		if (g.find("CD") != -1) lose++;
	}

	fout << n - lose;	

	fin.close();
	fout.close();
	return 0;
}