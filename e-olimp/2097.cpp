#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool difDigits(int n) {
	bool digits[] = {0,0,0,0,0,0,0,0,0,0};
	short d = 0;

	while (n) {
		d = n % 10;
		n /= 10;

		if (digits[d]) return false;
		digits[d] = 1;
	}

	return true;
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int a, b;
	fin >> a >> b;

	string res;

	for (int i = a; i <= b; i++) {
		if (difDigits(i)) res += to_string(i) + '\n';
	}

	fout << res;

	fin.close();
	fout.close();
	return 0;
}