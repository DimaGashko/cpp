#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	float base = ceil(float(n) / k) * 4;

	if ((n % k) % 2 == 0 || (n / k) % 2 == 0) {
		cout << base;
	}
	else {
		cout << base - 2;
	}

	system("pause");
	return 0;
}
