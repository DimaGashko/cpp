#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
	int n, tmp;
	fin >> n;

	vector<int> ns, res;
	
	for (int i = 0; i < n; i++) {
		fin >> tmp;
		ns.push_back(tmp);
		res.push_back(0);
	}

	sort(ns.begin(), ns.end());
	
	for (int i = 0, j = 0; i < n; i += 2, j++) {
		res[j] = ns[i];
	}

	for (int i = 1, j = n - 1; i < n; i += 2, j--) {
		res[j] = ns[i];
	}

	for (int i = 0; i < n; i++) {
		fout << res[i] << ' ';
	}
	

	fin.close();
	fout.close();
	return 0;
}