#include <iostream>

using namespace std;

int main() {
	int n, cur = 1, k, l;
	cin >> n >> k >> l;
	
	int **arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];

		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
		}
	}

	for (int j = 0; j < n - 1; j++) {
		arr[0][j] = cur++; //первая строка (без последнего элемента) - единици
	}

	int d = 0, i = 0, j = n - 1, a = n - 1;

	while (a >= 1) {
		for (int k = 0; k < 2; k++) {
			d = (d + 1) % 4;

			for (int p = 0; p < a; p++) {
				if (d == 0) arr[i][j++] = cur++;
				else if (d == 1) arr[i++][j] = cur++;
				else if (d == 2) arr[i][j--] = cur++;
				else if (d == 3) arr[i--][j] = cur++;
			}
 		}

		a--;
	}

	arr[i][j] = cur;

	cout << arr[k - 1][l - 1];
	return 0;
}