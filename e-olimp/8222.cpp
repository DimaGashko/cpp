#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	int i, j;

	getline(cin, s);
	cin >> i >> j;
	i--;j--;

	if (i > j) cout << 0;
	else {
		cout << j - i + 1 << endl
			<< s.substr(i, j - i + 1);
	}

	system("pause");
	return 0;
}