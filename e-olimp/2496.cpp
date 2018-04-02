#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
	string s;
	getline(fin, s);

	int pos = 0;
	while (true) {
		int left = s.find('(', pos);
		if (left == -1) break;

		int right = s.find(')', left + 1);
		if (right == -1) break;

		reverse(s.begin() + left + 1, s.begin() + right);
		s = s.substr(0, left) + s.substr(left + 1, right - left - 1) + s.substr(right + 1);

		pos = right - 1;
	}

	fout << s;

	fin.close();
	fout.close();
	return 0;
}