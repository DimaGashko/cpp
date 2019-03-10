#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<vector<int>>> res;
vector<int> currentTasks;

void init() {
	cin >> n;

	res = vector<vector<vector<int>>>(n);
}

void next(vector<vector<int>> &arr, int m, int i = -1) {
	currentTasks.push_back(i);

	if (m == -1) {
		vector<int> tasks(currentTasks.begin() + 1, currentTasks.end());
		arr.push_back(tasks);

		currentTasks.pop_back();
		return;
	}

	for (int ni = i + 1; ni + m < n; ni++) {
		next(arr, m - 1, ni);
	}

	currentTasks.pop_back();
}

void run() {
	for (int m = 0; m < n; m++) {
		next(res[m], m);
	}
}

void printResult() {
	for (int m = 0; m < n; m++) {

		for (auto& tasks : res[m]) {
			cout << (m + 1) << " ";

			for (auto& task : tasks) {
				cout << (task + 1) << " ";
			}

			cout << endl;
		}
	}
}

int main() {
	init();
	run();
	printResult();
		
	system("pause");
	return 0;
}