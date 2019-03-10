#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <ctime>

using namespace std;

int** getArr(int k, int l);
void writeArr(int **arr, int k, int l);

void printArr(int **arr, int k, int l, ofstream &fout);

void removeArr(int **arr, int k, int l);
bool inFillArea(int k, int i, int j);
void quickSort(int *arr, int l, int r);

void sortByTask(int **matr, int k, int l);

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	srand(time(0));

	int k, l;
	fin >> k;
	l = k;

	fout << "Размерность матрицы: " << k << " x " << l << endl;

	int **matr = getArr(k, l);
	writeArr(matr, k, l);

	sortByTask(matr, k, l);

	fout << endl << "Была сгенерирована матрица: " << endl;
	printArr(matr, k, l, fout);

	removeArr(matr, k, l);

	fin.close();
	fout.close();
	return 0;
}

void sortByTask(int **matr, int k, int l) {
	//Определение цифр, что находятся в fillArea
	int *nums = new int[k * l / 2 + k];
	int cur = 0;

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < l; j++) {
			if (inFillArea(k, i, j)) nums[cur++] = matr[i][j];
		}
	}

	quickSort(nums, 0, cur - 1);
	
	//Замена чисел отсортироваными
	for (int i = 0, cur = 0; i < k; i++) {
		for (int j = 0; j < l; j++) {
			if (inFillArea(k, i, j)) matr[i][j] = nums[cur++];
		}
	}

	delete[] nums;
}

void quickSort(int *arr, int l, int r) {
	int i = l, j = r, middle = arr[(i + j) / 2];

	do {
		while (middle < arr[i]) i++;
		while (middle > arr[j]) j--;

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

//Заполняет двумерный массив размером k x l случайными числами
void writeArr(int **arr, int k, int l) {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < l; j++) {
			if (inFillArea(k, i, j)) {
				arr[i][j] = 10 + rand() % 90;
			}
			else {
				arr[i][j] = 5;
			}

		}
	}

}

bool inFillArea(int k, int i, int j) {
	return (i <= j && k - i - 1 >= j)
		|| (i >= j && k - i - 1 <= j);
}

//Выводит двумерный массив в файнл
void printArr(int **arr, int k, int l, ofstream &fout) {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < l; j++) {
			fout << setw(3) << arr[i][j];
		}

		fout << endl;
	}

	fout << endl;
}

//Cоздает и возвращает двумерный массив размером k x l 
//Массив изначально заполняется нулями
int** getArr(int k, int l) {
	int **arr = new int *[k];

	for (int i = 0; i < k; i++) {
		arr[i] = new int[l];
	}

	return arr;
}

void removeArr(int **arr, int k, int l) {
	for (int i = 0; i < k; i++) {
		delete[] arr[i];
	}

	delete[] arr;
}