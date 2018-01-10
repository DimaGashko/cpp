#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n;
	fin >> n;

	long long res = 1;

	for (int i = 2; i <= n; i++) {
		res *= i;
	}

	fout << res;

	fin.close();
	fout.close();
	return 0;
}