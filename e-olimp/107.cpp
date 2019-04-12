#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int  min = 0, max = 0, x = 0;
	char t = ' ';

	while (fin >> t) {
		if (t == 'S') continue;

		x = (t == 'R') ? x + 1 : x - 1;

		if (x > max) max = x;
		else if (x < min) min = x;
	}

	fout << max - min + 1;

	fin.close();
	fout.close();
	return 0;
}