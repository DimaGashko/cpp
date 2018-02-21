#include <iostream>
#include <fstream>

using namespace std;

void quickSort(int *arr, int l, int r);

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	int *arr = new int[100000];

	int n = 0;
	while (fin >> arr[n]) { n++; }

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		fout << arr[i] << ' ';
	}

	fin.close();
	fout.close();

	delete[] arr;
	return 0;
}

void quickSort(int *arr, int l, int r) {
	int i = l, j = r, middle = arr[(i + j) / 2];

	do {
		while (middle > arr[i]) i++;
		while (middle < arr[j]) j--;

		if (i <= j) {
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;

			i++; j--;
		}

	} while (i < j);

	if (i < r) quickSort(arr, i, r);
	if (j > l) quickSort(arr, l, j);
}