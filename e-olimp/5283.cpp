#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	short n, max = 0, cur = 0, tmp;
	fin >> n;

	for (short i = 0; i < n; i++) {
		fin >> tmp;

		if (tmp > 0) {
			cur++;
		}
		
		if (tmp <= 0 || i == n - 1) {
			if (cur > max) max = cur;
			cur = 0;
		}
	}

	fout << max;

	fin.close();
	fout.close();
	return 0;
}