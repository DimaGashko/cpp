#include <iostream>
#include <fstream>

using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b) {
	while (a != 0 && b != 0) {
		if (a > b) a %= b;
		else b %= a;
	}

	return a + b;
}

unsigned long long lcm(unsigned long long a, unsigned long long b) {
	return a / gcd(a, b) * b;
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n;
	fin >> n;

	long long res = 1;

	for (int i = 2; i <= n; i++) {
		res = lcm(res, i);
	}

	fout << res;

	fin.close();
	fout.close();
	return 0;
}