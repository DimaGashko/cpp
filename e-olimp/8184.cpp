#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	vector<int> a;
	int tmp;

	for (int i = 0; i < 6; i++) {
		fin >> tmp;
		a.push_back(tmp);
	}

	sort(a.begin(), a.end());

	bool res = (
		a[0] == a[1] &&
		a[2] == a[3] &&
		a[4] == a[5] &&
		a[0]*a[0] + a[2]*a[2] == a[4]*a[4]
	);

	fout << (res ? "YES" : "NO");

	fin.close();
	fout.close();
	return 0;
}