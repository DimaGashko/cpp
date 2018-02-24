#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void quickSort(string *arr, int l, int r);

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	

	int n;
	fin >> n;

	string *words = new string[n];

	for (int i = 0; i < n; i++) {
		fin >> words[i];
	}
	
	quickSort(words, 0, n - 1);

	for (int i = 0; i < n; i++) {
		fout << words[i] << endl;
	}

	fin.close();
	fout.close();

	delete[] words;
	return 0;
}

void quickSort(string *arr, int l, int r) {
	int i = l, j = r;
	string middle = arr[(i + j) / 2];;

	do {
		while (middle > arr[i]) i++;
		while (middle < arr[j]) j--;

		if (i <= j) {
			swap(arr[i], arr[j]);
			i++; j--;
		}

	} while (i < j);

	if (i < r) quickSort(arr, i, r);
	if (j > l) quickSort(arr, l, j);
}