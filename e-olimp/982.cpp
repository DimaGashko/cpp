#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<vector<bool>> G;

ifstream fin("input.txt");
ofstream fout("output.txt");

void writeG();
void run(int v = 0, int prev = -1);
bool isYes();

G g;
vector<bool> vs;
int n = 0, m = 0;

int main() {
	writeG();
	run();
	
	fout << (isYes() ? "YES" : "NO");

	return 0;
}

void run(int v, int prev) {
	if (vs[v]) return;
	vs[v] = true;

	for (int i = 0; i < n; i++) {
		if (g[v][i] == 0) continue;

		run(i, v);
	}
}

bool isYes() {
	for (auto v : vs) {
		if (!v) return false;
	}

	return true;
}

void writeG() {
	fin >> n >> m;
	g = G(n, vector<bool>(n));

	for (int i = 0; i < m; i++) {
		int a, b;
		fin >> a >> b;

		a--; b--;

		g[a][b] = 1;
		g[b][a] = 1;
	}

	vs = vector<bool>(n);
}