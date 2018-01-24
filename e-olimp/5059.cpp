#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n;
	long long min, min2, tmp;

	fin >> n >> min >> min2;

	if (min > min2) swap(min, min2);

	for (int i = 0; i < n - 2; i++) {
		fin >> tmp;

		if (tmp < min) {
			min2 = min;
			min = tmp;
		}
		else if (tmp < min2 && tmp != min) {
			min2 = tmp;
		}
	}

	fout << min << ' ' << min2;

	fin.close();
	fout.close();
	return 0;
}