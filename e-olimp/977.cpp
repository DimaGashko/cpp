#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<vector<int>> G;

ifstream fin("input.txt");
ofstream fout("output.txt");

void writeGraph();
void writeVs();
void run(int v = 0, int prev = -1);
bool checkIsTree();

G g;
vector<bool> vs;
int n = 0;
int isLoop = false;

int main() {
	writeGraph();
	writeVs();
	run();
	
	fout << (checkIsTree() ? "YES" : "NO");

	return 0;
}

void run(int v, int prev) {
	if (isLoop) return;

	if (vs[v] == true) {
		isLoop = true;
		return;
	}

	vs[v] = true;

	for (int i = 0; i < n; i++) {
		if (g[v][i] == 0 || i == prev) continue;

		run(i, v);
	}
}

bool checkIsTree() {
	if (isLoop) return false;

	for (auto item : vs) {
		if (!item) return false;
	}

	return true;
}

void writeGraph() {
	fin >> n;

	g = G(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int val;
			fin >> val;

			g[i][j] = val;

			auto a = g[i][j];
		}
	}
}

void writeVs() {
	vs = vector<bool>(g.size());
}