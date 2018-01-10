#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	unsigned long long a, b, c = 1;
	fin >> a >> b;

	if (a == 0) c = (b == 0) ? 1 : 0;
	else if (b == 0) c = 1;
	else if (b == 1) c = a;
	else if (a == 1) c = 1;
	else {
		for (int i = 1; i <= b; i++) {
			c *= a;
		}
	}

	fout << c;

	fin.close();
	fout.close();
	return 0;
}