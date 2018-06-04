#include <iostream> 
#include <fstream> 

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

void printArr(int *arr, int len);
void writeArr(int *arr, int len);

void bubleSort(int *arr, int len);
void selectSort(int *arr, int len);

int main() {
	int n = 10;
	int *a = new int[n];

	writeArr(a, n);	
	selectSort(a, n);
	printArr(a, n);

	fin.close();
	fout.close();

	return 0;
}

void selectSort(int *arr, int len) {
	for (int i = 0; i < len; i++) {
		int extI = i;

		for (int j = i + 1; j < len; j++) {
			if (arr[j] < arr[extI]) extI = j;
		}
	
		swap(arr[i], arr[extI]);
	}
}

void bubleSort(int *arr, int len) {
	for (int i = 0; i < len; i++) {\
		for (int j = i + 1; j < len ; j++) {
			if (arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
			}
		}

	}
}

void printArr(int *arr, int len) {
	for (int i = 0; i < len; i++) {
		fout << arr[i] << " ";
	}

	fout << endl;
}

void writeArr(int *arr, int len) {
	for (int i = 0; i < len; i++) {
		fin >> arr[i];
	}
}
