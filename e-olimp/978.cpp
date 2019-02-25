#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef vector<vector<bool>> G;

void writeG();
void run(int v = 0, int prev = -1);
void printResult();

G g;
G tree;
vector<bool> vs;

int n = 0, m = 0;

int main() {

	writeG();
	run();
	printResult();

	return 0;
}

void run(int v, int prev) {
	if (vs[v]) return;
	vs[v] = true;

	if (prev != -1) {
		tree[v][prev] = 1;
		tree[prev][v] = 1;
	}

	for (int i = 0; i < n; i++) {
		if (g[v][i] == 0) continue;

		run(i, v);
	}
}

void printResult() {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (tree[i][j] == 0) continue;
			fout << i + 1 << " " << j + 1 << endl;
		}
	}
}

void writeG() {
	fin >> n >> m;

	g = G(n, vector<bool>(n));
	tree = G(n, vector<bool>(n));
	vs = vector<bool>(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		fin >> a >> b;
		a--; b--;

		g[a][b] = 1;
		g[b][a] = 1;
	}

}
