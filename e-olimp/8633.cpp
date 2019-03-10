#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;

	int res;

	if (n % 2 == 0) {
		res = 1 + ((n - 2) / 2) * 3;
	}
	else {
		res = 1 + ((n - 3) / 2) * 3 + 2;
	}

	cout << res << endl;

	system("pause");
	return 0;
}