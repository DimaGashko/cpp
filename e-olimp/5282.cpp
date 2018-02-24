#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("input.txt");

	short n, m;
	fin >> n >> m;

	short **arr = new short *[n];
	for (short i = 0; i < n; i++) {
		arr[i] = new short[m];

		for (short j = 0; j < m; j++) {
			fin >> arr[i][j];
		}
	}

	short *minR = new short[n];
	short *maxC = new short[m];

	//mins
	for (short i = 0; i < n; i++) {
		minR[i] = arr[i][0];

		for (short j = 1; j < m; j++) {
			if (arr[i][j] < minR[i]) minR[i] = arr[i][j];
		}
	}
	
	//maxs
	for (short j = 0; j < m; j++) {
		maxC[j] = arr[0][j];
		
		for (short i = 1; i < n; i++) {
			if (arr[i][j] > maxC[j]) maxC[j] = arr[i][j];
		}
	}

	//count
	int count = 0;

	for (short i = 0; i < n; i++) {
		for (short j = 0; j < m; j++) {
			if (arr[i][j] <= minR[i] && arr[i][j] >= maxC[j]) {
				count++;
			}
		}
	}

	//clean
	for (short i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	delete[] minR;
	delete[] maxC;

	cout << count;

	fin.close();
	return 0;
}