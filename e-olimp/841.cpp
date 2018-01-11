#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	short n, N;
	fin >> n;
	N = n;

	short **a = new short *[n];
	for (short i = 0; i < n; i++) {
		a[i] = new short[n];
	}

	n--;
	short i = 0, j = 0, m = 1;

	while (n >= 0) {
		for (short d = 1; d <= 4; d++) {
			for (short k = 0; k < n; k++) {
				if (i >= N || j >= N) break;
				a[i][j] = m++;

				if (d == 1) j++;
				else if (d == 2) i++;
				else if (d == 3) j--;
				else i--;
			}
		}

		n = n - 2;
		j++; i++;
	}

	if (N % 2 != 0) a[N / 2][N / 2] = N*N;

	for (short i = 0; i < N; i++) {
		for (short j = 0; j < N; j++) {
			fout << a[i][j] << ' ';
		}

		fout << endl;
	}

	for (short i = 0; i < N; i++) {
		delete[] a[i];
	}

	fin.close();
	fout.close();
	return 0;
}