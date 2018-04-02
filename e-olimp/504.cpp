#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
	int n;
	string tmp;
	fin >> n;

	getline(fin, tmp);

	for (int t = 0; t < n; t++) {
		getline(fin, tmp);
		string s = "--" + tmp + "--";

		int l = s.length() - 1, count = 0;

		for (int i = 2; i <= l - 2; i++) {

			bool check = (
				s[i] == '-' &&
				s[i + 1] != 'S' && s[i - 1] != 'S' &&
				s[i + 1] != 'B' && s[i + 2] != 'B'
			);

			if (check) count++;

		}

		fout << count << endl;
	}

	fin.close();
	fout.close();
	return 0;
}
