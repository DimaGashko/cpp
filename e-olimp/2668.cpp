#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n;
	fin >> n;

	if (n == 1) {
		fout << 0;
		return 0;
	}
	
	bool **arr = new bool*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new bool[n];

		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
		}
	}

	for (int j = 0; j < n - 1; j++) {
		arr[0][j] = 1; //первая строка (без последнего элемента) - единици
	}

	int d = 0, i = 0, j = n - 1, a = n - 1;

	while (a >= 1) {
		for (int k = 0; k < 2; k++) {
			d = (d + 1) % 4;

			for (int p = 0; p < a; p++) {
				if (d == 0) arr[i][j++] = 1;
				else if (d == 1) arr[i++][j] = 1;
				else if (d == 2) arr[i][j--] = 1;
				else if (d == 3) arr[i--][j] = 1;
			}
 		}

		a -= 2;
	}

	arr[i][j] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fout << arr[i][j];
		}

		fout << endl;
	}

	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	fin.close();
	fout.close();
	return 0;
}