#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

int sumDigits(int n) {
	int sum = 0;

	while (n) {
		sum += n % 10;
		n /= 10;
	}

	return sum;
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	string res;
	int n, s;
	fin >> n >> s;

	if (s == 0) {
		if (n == 1) res += '0';
	}
	else {
		for (int i = pow(10, n - 1); i < pow(10, n); i++) {
			if (sumDigits(i) == s) res += to_string(i) + '\n';
		}
	}
	
	fout << res;

	fin.close();
	fout.close();
	return 0;
}