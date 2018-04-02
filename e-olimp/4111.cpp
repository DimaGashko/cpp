#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
	string s1, s2;
	int t;

	fin >> t;

	for (int k = 0; k < t; k++) {
		fin >> s1 >> s2;

		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		
		fout << (s1 == s2 ? "YES" : "NO") << endl;
	}

	fin.close();
	fout.close();
	return 0;
}