#include <iostream>

using namespace std;

int main() {
	int n, p, tmp, count = 0;
	cin >> n >> p;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		count += tmp;
	}

	int left = p - 1,
		right = n - p;

	if (left > right) swap(left, right);


	cout << count + left * 2 + right;

	system("pause");
	return 0;
}