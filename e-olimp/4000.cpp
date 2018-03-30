#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

void findNodesInGroup(bool **gr, bool *nodes, int n, int cur) {
	for (int i = 0; i < n; i++) {
		if (gr[cur][i] && !nodes[i]) {
			nodes[i] = 1;
			findNodesInGroup(gr, nodes, n, i);
		}
	}
}

int main() {
	int n, s, count = 0;
	fin >> n >> s;

	s--;

	bool **gr = new bool*[n];
	for (int i = 0; i < n; i++) {
		gr[i] = new bool[n];

		for (int j = 0; j < n; j++) {
			fin >> gr[i][j];
		}
	}

	bool *nodes = new bool[n];
	for (int i = 0; i < n; i++) {
		nodes[i] = 0;
	}

	// - - -

	nodes[s] = 1;
	findNodesInGroup(gr, nodes, n, s);

	for (int i = 0; i < n; i++) {
		if (nodes[i]) count++;
	}

	fout << count;

	// - - -

	for (int i = 0; i < n; i++) {
		delete[] gr[i];
	}
	delete[] gr;

	fin.close();
	fout.close();
	return 0;
}