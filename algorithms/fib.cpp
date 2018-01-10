#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

long long fib(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	int l = 0, ll = 1;

	for (int i = 2; i < n; i++) {
		int prevLL = ll;

		ll += l;
		l = prevLL;
	}

	return l + ll;
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n;
	fin >> n;

	long long res;

	fout << fib(n);

	fin.close();
	fout.close();
	return 0;
}