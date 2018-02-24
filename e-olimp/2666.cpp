#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	short n;
	fin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (n - i - 1 == j) fout << 0;
			else if (n - i - 1 < j) fout << 1;
			else fout << 2;
		}

		fout << endl;
	}
	
	fin.close();
	fout.close();

	return 0;
}