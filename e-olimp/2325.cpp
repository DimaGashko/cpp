#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void quickSort(string &s, int l, int r);

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	string s, s2;
	fin >> s >> s2;

	s += s2;

	short len = s.length();

	quickSort(s, 0, len - 1);

	for (int i = 0; i < len; i++) {
		fout << s[i];
	}

	fout << endl;

	fin.close();
	fout.close();

	return 0;
}

void quickSort(string &s, int l, int r) {
	int i = l, j = r, middle = s[(i + j) / 2];

	do {
		while (middle < s[i]) i++;
		while (middle > s[j]) j--;

		if (i <= j) {
			char tmp = s[i];
			s[i] = s[j];
			s[j] = tmp;

			i++; j--;
		}

	} while (i < j);

	if (i < r) quickSort(s, i, r);
	if (j > l) quickSort(s, l, j);
}