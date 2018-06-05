#include <iostream> 
#include <fstream> 

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

void printArr(int *arr, int len);
void writeArr(int *arr, int len);

void bubleSort(int *arr, int len);
void selectSort(int *arr, int len);
void insertionSort(int *arr, int len);

int main() {
	int len = 10;
	int *arr = new int[len];

	writeArr(arr, len);
	insertionSort(arr, len);
	printArr(arr, len);

	delete[] arr;

	fin.close();
	fout.close();

	return 0;
}

void insertionSort(int *arr, int len) {
	for (int i = 1; i < len; i++) {
		for (int j = i; j >= 1; j--) {
			if (arr[j - 1] > arr[j]) {
				swap(arr[j], arr[j - 1]);
			}
		}

	}
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
