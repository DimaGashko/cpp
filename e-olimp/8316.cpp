#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void quickSort(char *s, int l, int r);

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	char s[100];
	fin >> s;

	short len = strlen(s);

	quickSort(s, 0, len - 1);

	for (int i = 0; i < len; i++) {
		fout << s[i];
	}

	fout << endl;

	for (int i = len - 1; i >= 0; i--) {
		fout << s[i];
	}

	fin.close();
	fout.close();

	return 0;
}

void quickSort(char *arr, int l, int r) {
	int i = l, j = r, middle = arr[(i + j) / 2];

	do {
		while (middle > arr[i]) i++;
		while (middle < arr[j]) j--;

		if (i <= j) {
			char tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;

			i++; j--;
		}

	} while (i < j);

	if (i < r) quickSort(arr, i, r);
	if (j > l) quickSort(arr, l, j);
}