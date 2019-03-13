#include <iostream>

using namespace std;


int main() {
	int n;
	cin >> n;

	int res = n;

	for (int i = 1; (res = (res >> i) << i) == n; i++) {}

	cout << res << endl;

	system("pause");
	return 0;
}