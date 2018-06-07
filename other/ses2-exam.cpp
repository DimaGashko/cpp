#include <iostream> 
#include <fstream> 
#include <cmath> 
#include <ctime> 

using namespace std;

template <typename T>
T ** createArr(int k, int l);

template <typename T>
void deleteArr(T **arr, int k);

template <typename T>
void writeArrRand(T **arr, int k, int l);

template <typename T>
void printArr(T **arr, int k, int l, ostream &out);

template <typename T>
int findMaxCol(T **arr, int k, int l);

template <typename T>
T ** addColAfter(T **arr, int k, int &l, int index);

int main() {
	ofstream fout("output.txt");
	srand(time(0));
	
	int k = 4, l = 6;
	auto **arr = createArr<short>(k, l);

	writeArrRand(arr, k, l);

	fout << "Созданный массив: " << endl;
	printArr(arr, k, l, fout);
	//printArr(arr, k, l, cout);

	int indexMax = findMaxCol(arr, k, l);
	fout << endl 
		<< "Индекс столбца, содержащий максимальный элемент: "
		<< indexMax << endl << endl;

	arr = addColAfter(arr, k, l, indexMax);

	fout << "Массив после добавления столбца: " << endl;
	printArr(arr, k, l, fout);

	deleteArr(arr, k);

	fout.close();
	return 0;
}

//Добавляет столбец в двумерный массив после указанного столбца
//Новые элементы заполняет нулями
template <typename T>
T ** addColAfter(T **arr, int k, int &l, int index) {
	T **newArr = createArr<T>(k, l + 1);
	l += 1;

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < l; j++) {
			if (j <= index) {
				newArr[i][j] = arr[i][j];
			}
			else if (j == index + 1) {
				newArr[i][j] = 0;
			}
			else {
				newArr[i][j] = arr[i][j - 1];
			}
		}
	}

	deleteArr(arr, k);
	return newArr;
}

//Создает и возврщает двумерный массив
//Использование: int arr** = createArr<int>(k, l)
template <typename T>
T ** createArr(int k, int l) {
	T **arr = new T* [k];
	for (int i = 0; i < k; i++) {
		arr[i] = new T[l];
	}

	return arr;
}

template <typename T>
void deleteArr(T **arr, int k) {
	if (!arr) return;

	for (int i = 0; i < k; i++) {
		if (arr[i]) delete[] arr[i];
	}

	delete[] arr;
}

//Заполняет массив случайными числами
template <typename T>
void writeArrRand(T **arr, int k, int l) {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < l; j++) {
			arr[i][j] = 10 + (rand() % 89);
		}
	}
}

//Выводит массив на поток вывода (fout, cout...)
template <typename T>
void printArr(T **arr, int k, int l, ostream &out) {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < l; j++) {
			out << arr[i][j] << ' ';
		}

		out << endl;
	}
}

//Находит индек столбца, содержащий максимальный элемент
//Если максимальные элементы есть в нескольких строках,
//То выбран будет первый справа
template <typename T>
int findMaxCol(T **arr, int k, int l) {
	int jMax = 0, max = arr[0][0];

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < l; j++) {
			if (arr[i][j] > max) {
				max = arr[i][j];
				jMax = j;
			}
		}
	}

	return jMax;
}

