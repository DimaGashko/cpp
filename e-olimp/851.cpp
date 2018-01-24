#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n;
	fin >> n;

	double s = 0;

	int **v = new int *[n];
	for (int i = 0; i < n; i++) {
		v[i] = new int[2];
		fin >> v[i][0] >> v[i][1];
	}

	for (int i = 0; i < n; i++) {
		int *a = v[i], *b = v[(i + 1) % n];
		s += (a[0] * b[1] - a[1] * b[0]) / 2.0;
	}

	fout << fixed << setprecision(1) << (s > 0 ? s : -s);

	delete[] v;

	fin.close();
	fout.close();
	return 0;
}