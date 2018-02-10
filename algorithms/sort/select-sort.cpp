//select sort (выбором)

#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>

using namespace std;

void writeArr(int *arr, int len);
void printArr(int *arr, int len, ofstream &fout, char sep = ' ');

void sort(int *arr, int n);

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	srand(time(0));

	int len;
	fin >> len;

	int *arr = new int[len];
	
	writeArr(arr, len);
	//printArr(arr, len, fout, '\n');

	sort(arr, len);
	printArr(arr, len, fout, '\n');

	fin.close();
	fout.close();
	return 0;
}

void sort(int *arr, int n) {
	for (int i = 0; i < n; i++) {

		int iMin = i;
		for (int j = i; j < n; j++) {
			if (arr[j] < arr[iMin]) iMin = j;
		}

		if (arr[i] != arr[iMin]) {
			int tmp = arr[i];
			arr[i] = arr[iMin];
			arr[iMin] = tmp;
		}
	}

}

void writeArr(int *arr, int len) {
	for (int i = 0; i < len; i++) {
		arr[i] = rand() % 10000;
	}
}

void printArr(int *arr, int len, ofstream &fout, char sep) {
	for (int i = 0; i < len; i++) {
		fout << arr[i] << sep;
	}
}