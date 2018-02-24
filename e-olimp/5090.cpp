#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("input.txt");

	//init
	short n;
	fin >> n;

	int **arr = new int *[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];

		for (int j = 0; j < n; j++) {
			fin >> arr[i][j];
		}
	}

	int maxR = -1, minC = 1E9;
	int iMax = 0, iMin = 0;

	//max
	for (int i = 0; i < n; i++) {
		int sum = arr[i][0];

		for (int j = 1; j < n; j++) {
			sum += arr[i][j];
		}

		if (sum > maxR) {
			maxR = sum;
			iMax = i;
		}
	}

	//min
	for (int j = 0; j < n; j++) {
		int sum = arr[0][j];

		for (int i = 1; i < n; i++) {
			sum += arr[i][j];
		}

		if (sum < minC) {
			minC = sum;
			iMin = j;
		}
	}

	cout << arr[iMax][iMin] << endl;

	//clean
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	fin.close();

	system("pause");
	return 0;
}