#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef vector<vector<int>> G;

G g;
vector<int> vVal;
int n;

int a, b, minW = 1e10;

void writeG() {
	fin >> n;

	g = G(n, vector<int>(n));
	vVal = vector<int>(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fin >> g[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		fin >> vVal[i];
	}
}

void nextV(int v) {
	for (int i = 0; i < n; i++) {
		int w = g[v][i];
		if (w == 0) continue;

		if (vVal[v] == 0 && vVal[i] == 1 && w < minW) {
			a = v;
			b = i;
			minW = w;
		}
		
	}

}

int main() {
	writeG();

	for (int i = 0; i < n; i++) {
		nextV(i);
	}

	fout << a + 1 << " " << b + 1;

	return 0;
}