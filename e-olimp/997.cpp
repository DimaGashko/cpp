#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos {
	Pos() : Pos(0, 0) {}
	Pos(int i, int j) : i(i), j(j) {}
	int i, j;
};

int n;
Pos start;
Pos goal;

vector<vector<bool>> visited;
vector<vector<Pos>> cameFrom;

bool isEmpty(Pos pos) {
	if (pos.i < 0 || pos.j < 0 || pos.i >= n || pos.j >= n) return false;

	return true;
}

bool posEquals(Pos a, Pos b) {
	return a.i == b.i && a.j == b.j;
}

void init() {
	cin >> n;
	cin >> start.j >> start.i;
	cin >> goal.j >> goal.i;

	start.i--; start.j--;
	goal.i--; goal.j--;

	visited = vector<vector<bool>>(n, vector<bool>(n));
	cameFrom = vector<vector<Pos>>(n, vector<Pos>(n));
}

void run() {
	queue<Pos> frontier;
	frontier.push(start);

	while (!frontier.empty()) {
		Pos current = frontier.front();
		frontier.pop();

		if (posEquals(current, goal)) {
			return;
		}

		vector<Pos> nexts(8);

		nexts[0] = Pos(current.i - 2, current.j - 1);
		nexts[1] = Pos(current.i - 2, current.j + 1);
		nexts[2] = Pos(current.i - 1, current.j + 2);
		nexts[3] = Pos(current.i + 1, current.j + 2);
		nexts[4] = Pos(current.i + 2, current.j + 1);
		nexts[5] = Pos(current.i + 2, current.j - 1);
		nexts[6] = Pos(current.i + 1, current.j - 2);
		nexts[7] = Pos(current.i - 1, current.j - 2);

		for (auto next : nexts) {
			if (!isEmpty(next) || visited[next.i][next.j]) continue;

			visited[next.i][next.j] = true;
			cameFrom[next.i][next.j] = current;
			frontier.push(next);
		}
	}

}

void printResults() {
	Pos next = goal;
	int steps = 0;

	while (!posEquals(next, start)) {
		steps++;
		next = cameFrom[next.i][next.j];
	}

	cout << steps << endl;
}

int main() {
	init();
	run();
	printResults();
	
	system("pause");
	return 0;
}