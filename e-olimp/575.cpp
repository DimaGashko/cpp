#include <iostream>

using namespace std;

int main() {
	int k = 0;
	cin >> k;

	cout << (k < 3 ? k : (k - 3) * 3 + 3);

	return 0;
}