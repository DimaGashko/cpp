#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int a, b;
	fin >> a >> b;

	if (a > b) swap(a, b);

	fout << a << ' ' << b << endl;

	fin.close();
	fout.close();
	return 0;
}