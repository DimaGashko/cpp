#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	
	int n, cer = 0, count = 0;
	fin >> n;

	int *all = new int[n];
	for (int i = 0; i < n; i++) {
		fin >> all[i];
	}

	for (int i = 0; i < n; i++) {
		cer += all[i];
	}

	cer /= n;

	for (int i = 0; i < n; i++) {
		if (all[i] > cer) count++;
	}

	fout << count;

	fin.close();
	fout.close();
	return 0;
}