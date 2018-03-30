#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

void findS(string *m, int n, int k, int l, int &S) {
	if (m[k][l] == '*') return;
	m[k][l] = '*';
	S++;

	//Вокруг лабиринта - стены -> никогда не будет выхода за граници массива
	//Перемещяемся на все соседние клетки
	findS(m, n, k - 1, l, S); //left
	findS(m, n, k + 1, l, S); //right
	findS(m, n, k, l - 1, S); //top
	findS(m, n, k, l + 1, S); //bottom
}

int main() {
	int n, k, l, S = 0;
	fin >> n;

	string *maze = new string[n];
	for (int i = 0; i < n; i++) {
		fin >> maze[i];
	}

	fin >> k >> l;
	k--;
	l--;

	// - - -
	findS(maze, n, k, l, S);
	fout << S;
	// - - -

	delete[] maze;

	fin.close();
	fout.close();
	return 0;
}