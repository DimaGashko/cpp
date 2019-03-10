#include <iostream>
#include <string>

using namespace std;

int main() {
	long long num;
	cin >> num;

	int max = 0;

	while (num) {
		int d = num % 10;
		if (d > max) max = d;

		num /= 10;
	}

	cout << max << endl;

	system("pause");
	return 0;
}