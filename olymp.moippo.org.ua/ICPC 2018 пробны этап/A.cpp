#include <iostream>

using namespace std;

int main() {
	float n, s, p;
	cin >> n >> p >> s;

	cout << int(s / (n * (p / 100 + 1))) << endl;

	system("pause");
	return 0;
}