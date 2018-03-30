#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int x, n, tmp;
	fin >> x >> n;

	bool *goods = new bool[n];
	for (int i = 0; i < n; i++) {
		goods[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fin >> tmp;
			if (tmp == x) goods[j] = true;
		}
	}

	for (int j = 0; j < n; j++) {
		fout << (goods[j] ? "YES" : "NO") << endl;
	}

	delete[] goods;
	
	fin.close();
	fout.close();
	return 0;
}