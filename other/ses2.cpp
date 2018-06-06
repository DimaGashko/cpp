#include <iostream> 
#include <fstream> 
#include <cmath> 
#include <ctime> 

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct test {
	test(int n) {
		a = n;
	}

	int a;
};

void printArr(int *arr, int len);
void writeArr(int *arr, int len);

void printArr(int **arr, int m, int n);
void writeArr(int **arr, int m, int n);

void bubleSort(int *arr, int len);
void selectSort(int *arr, int len);
void insertionSort(int *arr, int len);

void aa(istream &in, ostream &out) {
	
};

int main() {
	aa(fin, fout);
	aa(cin, cout);

	union {
		int q, w;
	};

	cin >> q;
	cout << q;

	test t(999);
	fout << t.a;

	return 0;

	srand(time(0));

	int len = 10;
	int **arr = new int*[len];
	for (int i = 0; i < len; i++) {
		arr[i] = new int[len];
	}

	writeArr(arr, len, len);
	printArr(arr, len, len);

	for (int i = 0; i < len; i++) {
		delete[] arr[i];
	}
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
		arr[i] = 10 + (rand() % 89);
	}
}

void printArr(int **arr, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			fout << arr[i][j] << " ";
		}

		fout << endl;
	}

	fout << endl;
}

void writeArr(int **arr, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 10 + (rand() % 89);
		}
	}
}
