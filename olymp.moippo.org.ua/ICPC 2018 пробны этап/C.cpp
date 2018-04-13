#include <iostream>

using namespace std;

int main() {
	int s, n, mr = 0, mv = 0, tmp;
	cin >> s >> n;

	for (int i = 0; i < n; i++) {
		cin >> tmp;

		if (mr + tmp <= s) mr += tmp;
		else mv += tmp;
	}

	cout << mr << ' ' << mv << endl;

	system("pause");
	return 0;
}