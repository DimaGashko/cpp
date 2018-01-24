#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n, m, tmp, plus = 0;
	short t;
	fin >> n >> m;

	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		fin >> a[i];
	}

	for (int i = 0; i < m; i++) {
		fin >> t >> tmp;

		if (t == 1) {
			fin >> a[tmp - 1];
			a[tmp - 1] -= plus;
		}
		else if (t == 2) {
			plus += tmp;
		}
		else if (t == 3) {
			fout << a[tmp - 1] + plus << endl;
		}
	}

	delete[] a;

	fin.close();
	fout.close();
	return 0;
}