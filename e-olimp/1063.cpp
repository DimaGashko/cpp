#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef vector<vector<bool>> G;

G g;
vector<bool> vs;
int gN = 0;
int parts = 0;

int getNextV() {
	for (int i = 0; i < gN; i++) {
		if (vs[i] == 0) return i;
	}

	return -1;
}

void writeG() {
	int m, n;
	fin >> m >> n;

	vector<string> strMap(m);

	for (int i = 0; i < m; i++) {
		string row;
		fin >> row;

		if (row.empty()) {
			continue;
		}

		strMap[i] = row;
	}

	map<pair<int, int>, int> vsIndexes;

	for (int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if (strMap[i][j] == '.') continue;
			gN++;
			vsIndexes[pair<int, int>(i, j)] = gN;
		}
	}

	g = G(gN, vector<bool>(gN));
	vs = vector<bool>(gN);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (strMap[i][j] == '.') continue;

			int aIndex = vsIndexes[pair<int, int>(i, j)] - 1;
			int lIndex = vsIndexes[pair<int, int>(i, j - 1)] - 1;
			int tIndex = vsIndexes[pair<int, int>(i - 1, j)] - 1;
			int rIndex = vsIndexes[pair<int, int>(i, j + 1)] - 1;
			int bIndex = vsIndexes[pair<int, int>(i + 1, j)] - 1;

			if (lIndex != -1) g[aIndex][lIndex] = 1;
			if (tIndex != -1) g[aIndex][tIndex] = 1;
			if (rIndex != -1) g[aIndex][rIndex] = 1;
			if (bIndex != -1) g[aIndex][bIndex] = 1;
		}
	}

}

void run(int v, int prev = -1) {
	if (vs[v] == true) return;
	vs[v] = true;

	for (int i = 0; i < gN; i++) {
		if (g[v][i] == 0 || i == prev) continue;

		run(i, v);
	}
}

int main() {
	writeG();

	while (true) {
		int nextV = getNextV();
		if (nextV == -1) break;

		run(nextV);
		parts++;
	}

	fout << parts;

	return 0;
}