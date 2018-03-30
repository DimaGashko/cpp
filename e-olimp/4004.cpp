#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

bool isFor = false;

void check(bool **gr, int *uses, int n, int node, int startNode) {
	if (uses[node] == startNode) {
		if (node == startNode) isFor = true;
		return;
	}

	uses[node] = startNode;

	for (int i = 0; i < n; i++) {
		if (gr[node][i]) check(gr, uses, n, i, startNode);
	}
}

int main() {
	int n;
	fin >> n;

	bool **gr = new bool*[n];
	for (int i = 0; i < n; i++) {
		gr[i] = new bool[n];

		for (int j = 0; j < n; j++) {
			fin >> gr[i][j];
		}
	}

	int *uses = new int[n];
	for (int i = 0; i < n; i++) {
		uses[i] = -1;
	}

	// - - -

	for (int i = 0; i < n; i++) {
		if (isFor) break;
		check(gr, uses, n, i, i);
	}

	fout << isFor;

	// - - -

	for (int j = 0; j < n; j++) {
		delete[] gr[j];
	}
	delete[] gr;

	fin.close();
	fout.close();
	return 0;
}