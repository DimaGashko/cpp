#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n;
	fin >> n;

	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		fin >> a[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		fout << a[i] << ' ';
	}

	delete[] a;

	fin.close();
	fout.close();
	return 0;
}