#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n, m, count = 0;
	cin >> n >> m;

	char **s = new char *[n];
	for (int i = 0; i < n; i++) {
		s[i] = new char[m];

		for (int j = 0; j < m; j++) {
			cin >> s[i][j];
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '#') continue;

			if (j + 1 < m && s[i][j + 1] == '.') count++;
			if (j - 1 >= 0 && s[i][j - 1] == '.') count++;
			if (i + 1 < n && s[i + 1][j] == '.') count++;
			if (i - 1 >= 0 && s[i - 1][j] == '.') count++;
		
		}
	}

	cout << count / 2 << endl;

	system("pause");
	return 0;
}