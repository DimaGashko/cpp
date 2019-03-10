#include <iostream>

using namespace std;

int getMulOfDigits(int n) {
	int res = 1;

	while (n) {
		res *= n % 10;
		n /= 10;
	}

	return res;
}

int main() {
	int s, n; 
	cin >> s >> n;

	int k = 5000;

	int* f = new int[k];
	for (int i = 0; i < k; i++) {
		f[i] = 0;
	}

	for (int i = s; i <= n; i++) {
		f[getMulOfDigits(i)]++;
	}

	int common = 0;
	int count = 0;

	for (int i = 1; i < k; i++) {
		if (!f[i]) continue;

		if (f[i] > count) {
			common = i;
			count = f[i];
		}
	}

	if (common == 0) {
		cout << 0 << endl;
	}
	else {
		cout << common << " " << count << endl;
	}

	system("pause");
	return 0;
}