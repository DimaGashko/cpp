#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> maze;
vector<vector<bool>> visited;
int n = 0;
int visibleWalls = -4;

void printResults() {
	int cost = visibleWalls * 9;

	cout << cost << endl;
}

void writeMaze() {
	cin >> n;

	maze = vector<string>(n);
	visited = vector<vector<bool>>(n, vector<bool>(n));

	for (int i = 0; i < n; i++) {
		cin >> maze[i];
	}
}

bool isWall(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n) return true;

	return (maze[x][y] == '#');
}

void next(int x, int y) {
	if (visited[x][y]) return;
	visited[x][y] = true;

	if (isWall(x, y - 1)) visibleWalls++;
	else next(x, y - 1);

	if (isWall(x - 1, y)) visibleWalls++;
	else next(x - 1, y);

	if (isWall(x, y + 1)) visibleWalls++;
	else next(x, y + 1);

	if (isWall(x + 1, y)) visibleWalls++;
	else next(x + 1, y);
}

int main() {
	writeMaze();

	next(0, 0);
	next(n - 1, n - 1);

	printResults();
	
	system("pause");
	return 0;
}
