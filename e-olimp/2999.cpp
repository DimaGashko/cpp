#include <iostream>
#include <fstream>

using namespace std;

int f(int m, int n) {
	return (0 < m && m < n) ?
		f(m - 1, n - 1) + f(m, n - 1) : 1;
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int m, n;
	fin >> n >> m;

	fout << f(m, n);

	fin.close();
	fout.close();
	return 0;
}