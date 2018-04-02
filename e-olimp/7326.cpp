#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
	string s;
	fin >> s;

	int len = s.length(), max = 0, cur = 0;

	for (int i = 0; i < len; i++) {
		if (s[i] == 'k') cur++;
		if (s[i] == 'p' || i == len - 1) {
			if (cur > max) max = cur;
			cur = 0;
		}
	}

	fout << max;

	fin.close();
	fout.close();
	return 0;
}
