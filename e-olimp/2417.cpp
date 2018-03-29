#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	int n, m;

	while (fin >> n >> m) {
		fout << (n + m) * 2 << ' '
			<< n * m << endl;
	}

	fin.close();
	fout.close();

	return 0;
}