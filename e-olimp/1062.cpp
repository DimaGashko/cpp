#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>

using namespace std;

struct Pos {
	Pos(): Pos(0, 0) {}
	Pos(int x, int y): x(x), y(y) {}
	int x = 0, y = 0;
};

int n;
Pos start;
Pos goal;
bool found = false;
vector<string> taskMap;
vector<vector<bool>> visited;
vector<vector<Pos>> cameFrom;

void init() {
	cin >> n;

	taskMap = vector<string>(n);
	visited = vector<vector<bool>>(n, vector<bool>(n));
	cameFrom = vector<vector<Pos>>(n, vector<Pos>(n));

	for (int i = 0; i < n; i++) {
		cin >> taskMap[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			auto item = taskMap[i][j];

			if (item != '@' && item != 'X') {
				continue;
			}

			Pos pos(i, j);

			if (item == '@') start = pos;
			else if (item == 'X') goal = pos;
		}
	}
}

bool equals(Pos a, Pos b) {
	return a.x == b.x && a.y == b.y;
}

bool isEmpty(Pos pos) {
	if (pos.x < 0 || pos.y < 0 || pos.x >= n || pos.y >= n) return false;

	return taskMap[pos.x][pos.y] != 'O';
}

void run() {
	queue<Pos> frointer;
	frointer.push(start);
	visited[start.x][start.y] = true;

	while (!frointer.empty()) {
		auto pos = frointer.front();
		frointer.pop();

		if (equals(pos, goal)) {
			found = true;
			break;
		}

		vector<Pos> nexts(4);
		nexts[0] = Pos(pos.x - 1, pos.y);
		nexts[1] = Pos(pos.x, pos.y - 1);
		nexts[2] = Pos(pos.x + 1, pos.y);
		nexts[3] = Pos(pos.x, pos.y + 1);

		for (auto& next : nexts) {
			if (!isEmpty(next) || visited[next.x][next.y]) continue;

			frointer.push(next);
			visited[next.x][next.y] = true;
			cameFrom[next.x][next.y] = pos;
		}
	}	
}

void printResult() {
	if (!found) {
		cout << "N" << endl;
		return;
	}

	cout << "Y" << endl;

	auto next = goal;

	taskMap[next.x][next.y] = '+';

	while (!equals(next, start)) {
		taskMap[next.x][next.y] = '+';
		next = cameFrom[next.x][next.y];
	}

	for (auto row : taskMap) {
		cout << row << endl;
	}
}

int main() {
	init();
	run();
	printResult();

	system("pause");
	return 0;
}