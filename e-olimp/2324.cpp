#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
	vector<int> ns;
	int n, tmp;
	fin >> n;

	for (int i = 0; i < n; i++) {
		fin >> tmp;
		ns.push_back(tmp);
	}

	sort(ns.begin(), ns.end());

	for (int i = 0; i < n; i++) {
		fout << ns[i] << ' ';
	}

	fin.close();
	fout.close();
	return 0;
}