#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct line {
	int l = 0, r = 0;
};

void CountingSort(line *a, int n) {
	int max = 10000, min = 1;
	for (int i = 0; i < n; i++) {
		if (a[i].l > max) max = a[i].l;
		if (a[i].l < min) min = a[i].l;
	}

	int *c = new int[max + 1 - min];
	for (int i = 0; i < max + 1 - min; i++) {
		c[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		c[a[i].l - min] = c[a[i].l - min] + 1;
	}
	int i = 0;
	for (int j = min; j < max + 1; j++) {
		while (c[j - min] != 0) {
			a[i].l = j;
			c[j - min]--;
			i++;
		}
	}

	delete[] c;
}

void quickSort(line *arr, int l, int r) {
	int i = l, j = r, middle = arr[(i + j) / 2].l;

	do {
		while (middle > arr[i].l) i++;
		while (middle < arr[j].l) j--;

		if (i <= j) {
			line tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;

			i++; j--;
		}

	} while (i < j);

	if (i < r) quickSort(arr, i, r);
	if (j > l) quickSort(arr, l, j);
}

int getStart(line *ls, int tmp, int l, int r) {
	if (l <= r) return l;
	int middle = (l + r) / 2;

	return (ls[middle].l < tmp) ?
		getStart(ls, tmp, middle, r) :
		getStart(ls, tmp, l, middle);
}

int main() {
	int l, m, n;
	fin >> l >> n >> m;

	line *ls = new line[n];

	for (int i = 0; i < n; i++) {
		ls[i] = {};
		fin >> ls[i].l >> ls[i].r;
	}

	quickSort(ls, 0, n - 1);

	int tmp;
	for (int i = 0; i < m; i++) {
		fin >> tmp;

		int count = 0;
		for (int i = getStart(ls, tmp, 0, n - 1); i < n; i++) {
			if (ls[i].l <= tmp && ls[i].r >= tmp) count++;
		}

		fout << count << ' ';
	}

	fout.close();
	return 0;
}