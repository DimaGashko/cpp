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

int getElement(int **matr, int l, int index);
void swapElement(int **matr, int l, int i, int j);
void quickSort(int **arr, int k, int m, int l, int r);

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	//srand(time(0));

	int k, l;
	fin >> k;
	l = k;

	fout << "Размерность матрицы: " << k << " x " << l << endl;

	int **matr = getArr(k, l);
	writeArr(matr, k, l);

	quickSort(matr, k, l, 0, k*l - 1);

	fout << endl << "Была сгенерирована матрица: " << endl;
	printArr(matr, k, l, fout);

	removeArr(matr, k, l);

	fin.close();
	fout.close();
	return 0;
}

int getElement(int **matr, int l, int index) {
	return matr[index / l][index % l];
}

void swapElement(int **matr, int l, int i, int j) {
	int tmp = matr[i / l][i % l];
	matr[i / l][i % l] = matr[j / l][j % l];
	matr[j / l][j % l] = tmp;
}

void quickSort(int **arr, int k, int m, int l, int r) {
	int i = l, j = r, middle = getElement(arr, m, (i + j) / 2);

	do {
		while (middle < getElement(arr, m, i)) i++;
		while (middle > getElement(arr, m, j)) j--;

		//while (i < j && (!inFillArea(k, i/m, i%m) || middle < getElement(arr, m, i))) i++;
		//while (i < j && (!inFillArea(k, j/m, j%m) || middle > getElement(arr, m, j))) j--;

		//while (i < j && (arr[i/m][i%m] == 5 || middle < getElement(arr, m, i))) i++;
		//while (i < j && (arr[j/m][j%m] == 5 || middle > getElement(arr, m, j))) j--;

		if (i <= j) {
			swapElement(arr, m, i, j);
			i++; j--;
		}

	} while (i < j);

	if (i < r) quickSort(arr, k, m, i, r);
	if (j > l) quickSort(arr, k, m, l, j);
}

bool inFillArea(int k, int i, int j) {
	return (i <= j && k - i - 1 >= j)
		|| (i >= j && k - i - 1 <= j);
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

void removeArr(int **arr, int k, int l) {
	for (int i = 0; i < k; i++) {
		delete[] arr[i];
	}

	delete[] arr;
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