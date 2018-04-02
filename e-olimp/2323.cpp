#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

bool top(int i, int j) {
	return i < j;
}

bool bottom(int i, int j) {
	return i > j;
}

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
	string s, s1, s2;
	fin >> s;

	s1 = s; s2 = s;

	sort(s1.begin(), s1.end(), bottom);
	sort(s2.begin(), s2.end(), top);

	string s3;
	for (int i = 0; i < s2.length(); i++) {
		if (s2[i] != '0') s3 += s2[i];
	}

	fout << atoi(s1.c_str()) + atoi(s3.c_str());

	fin.close();
	fout.close();
	return 0;
}