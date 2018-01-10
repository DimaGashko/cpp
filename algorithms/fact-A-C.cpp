#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int fact(int n) {
	if (n <= 1) return 1;
	int res = 2;

	for (int i = 3; i <= n; i++) {
		res *= i;
	}

	return res;
}

int A(int n, int k) {
	int res = 1;

	for (int i = 0; i < k; i++) {
		res *= n - i;
	}

	return res;
}

int C(int n, int k) {
	return A(n, k) / fact(k);
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n, k, res;
	fin >> n >> k;

	if (n == 1) res = 1;
	else if (k == 1) res = n;
	else res = C(n, k);

	fout << res;

	fin.close();
	fout.close();
	return 0;
}