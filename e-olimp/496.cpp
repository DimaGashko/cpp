#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

void toUpperCase(string &s) {
	for (char c : s) toupper(c);
}

int main() {
	string s1, s2;
	int t;

	fin >> t;

	for (int k = 0; k < t; k++) {
		fin >> s1 >> s2;

		for (int i = 0; i < s1.length(); i++) {
			s1[i] = tolower(s1[i]);
		}

		for (int i = 0; i < s2.length(); i++) {
			s2[i] = tolower(s2[i]);
		}

		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		
		fout << (s1 == s2 ? "Yes" : "No") << endl;
	}

	fin.close();
	fout.close();
	return 0;
}
