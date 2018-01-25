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

	int min = a[0], max = a[0];

	for (int i = 1; i < n; i++) {
		if (a[i] < min) min = a[i];
		else if (a[i] > max) max = a[i];
	}

	for (int i = 0; i < n; i++) {
		if (a[i] == max) a[i] = min;
	}

	for (int i = 0; i < n; i++) {
		fout << a[i] << ' ';
	}

	delete[] a;

	fin.close();
	fout.close();
	return 0;
}