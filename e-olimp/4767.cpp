#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef vector<vector<bool>> G;

void writeG();
void printRes();

G g;
int n = 0, m = 0;

int main() {

	writeG();
	printRes();

	return 0;
}

void writeG() {
	fin >> n >> m;

	g = G(n, vector<bool>(n));

	for (int i = 0; i < m; i++) {
		int a, b;
		fin >> a >> b;
		a--; b--;

		g[a][b] = 1;
	}
}

void printRes() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j != 0) fout << " ";
			fout << g[i][j];
		}
		fout << endl;
	}
}
