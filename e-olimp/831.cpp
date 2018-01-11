#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void findOps(vector<int> &xs, vector<bool> &ops, int s, bool t, int i, int n, bool &find, int res_ = 0) {
	if (find) return;

	int res = res_;

	if (i == 0) {
		res = xs[0];
	}

	if (i > 0 && i < n) {
		res += (t) ? xs[i] : -xs[i];
		ops[i - 1] = t;
	} 

	if (i < n) {
		findOps(xs, ops, s, t, i + 1, n, find, res);
		findOps(xs, ops, s, !t, i + 1, n, find, res);
	}
	else if (res == s) {
		find = true;
		return;
	}
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n, s;
	fin >> n >> s;

	vector<int> xs(n);
	for (short i = 0; i < n; i++) {
		fin >> xs[i];
	}

	vector<bool> ops(n - 1);

	bool find = false;
	findOps(xs, ops, s, 0, -1, n, find);

	if (!find) fout << "No solution";
	else {
		fout << xs[0];

		for (int i = 0; i < n - 1; i++) {
			fout << (ops[i] ? '+' : '-') << xs[i + 1];
		}

		fout << '=' << s;
	}

	fout << endl;

	fin.close();
	fout.close();
	return 0;
}