#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct circle {
	int a, b, r;
	bool isInside(int x, int y) {
		return pow(x - a, 2) + pow(y - b, 2) <= r * r;
	}
	void input() {
		fin >> a >> b >> r;
	}
};

int max(int a, int b) {
	return (a > b) ? a : b;
}

int min(int a, int b) {
	return (a < b) ? a : b;
}

int main() {
	circle n, m;

	n.input();
	m.input();

	int dots = 0;

	int l = min(n.a - n.r, m.a - m.r);
	int r = max(n.a + n.r, m.a + m.r);

	int t = min(n.b - n.r, m.b - m.r);
	int b = max(n.b + n.r, m.b + m.r);

	for (int i = l; i <= r; i++) {
		for (int j = t; j <= b; j++) {

			if (n.isInside(i, j) || m.isInside(i, j)) {
				dots++;
			}

		}
	}

	fout << dots;

	fin.close();
	fout.close();
	return 0;
}