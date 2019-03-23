#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, prev, next, len = 1;
	cin >> n >> prev;

	vector<int> max{ 1 };

	for (int i = 1; i < n; i++) {
		cin >> next;

		if (prev + 1 == next) {
			len++;
			max.push_back(len);
		}
		else {
			max.push_back(len);
			len = 1;
		}

		prev = next;
	}

	sort(max.begin(), max.end());
	cout << max.back() << endl;

	system("pause");
	return 0;
}