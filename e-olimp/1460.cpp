#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n, a, b, c, d;
	fin >> n >> a >> b >> c >> d;
	a--; b--; c--; d--;

	int *s = new int[n];
	for (int i = 0; i < n; i++) {
		s[i] = i + 1;
	}

	for (int p = 0; p < 2; p++) {
		for (int i = a; i < (a + b) / 2.0; i++) {
			swap(s[i], s[a + b - i]);
		}

		a = c;
		b = d;
	}

	for (int i = 0; i < n; i++) {
		fout << s[i] << ' ';
	}

	fin.close();
	fout.close();
	return 0;
}