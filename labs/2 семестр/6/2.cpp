#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

void add() {
	cout << "add\n";
}

void printAll() {
	cout << "print\n";
}

void printSort() {
	cout << "sort\n";
}

void printByPopul() {
	cout << "byPopul\n";
}

void printBySAndPolul() {
	cout << "bySAndPopul\n";
}

void clearConsole() {
	system("cls");
}

int getNumber(const char label[]) {
	cout << label;

	while (true) {
		int val;
		cin >> val;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Произошла ошибка. Введите еще раз: ";
		}
		else {
			cin.ignore(32767, '\n');
			return val;
		}

	}

}

void printLine(char symbol = '-', short count = 20) {
	for (int i = 0; i < count; i++) {
		cout << symbol;
	}

	cout << endl;
}

int askCommand() {
	cout << "Выберите команду: " << endl 
		<< "1. Добавить запись в файл" << endl
		<< "2. Вывести все страны" << endl
		<< "3. Вывести все странны отсотированными" << endl
		<< "4. Вывести страны с населением от min до max" << endl
		<< "5. Вывести страны с площей от min до max и населением боьше n" << endl
		<< endl
		<< "6. Очистить экран" << endl
		<< "0. Выход" << endl << endl;

	return getNumber("> ") - 1;
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int menuLengh = 6;
	void(*menu[menuLengh])() = { add, printAll, printSort, printByPopul, printBySAndPolul, clearConsole };

	int command;

	while (1) {
		command = askCommand();
		if (command == -1) break;

		if (command < menuLengh) {
			menu[command]();
		} 
		else {
			cout << "Неправильная команда" << endl;
		} 
	}

	return 0;
}


/*#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

struct country {
	string name;
	string capital;
	long long population;
	int S;

	void print() {
		cout << name << "("
			<< "столица: " << capital
			<< "; население: " << population
			<< "; площадь: " << S << " кв. км)" << endl;
	}
};

void writeCountry(country *countries, int len, ifstream &fin);
void printCountry(country *countries, int len);

void quickSort(country *arr, int l, int r);
void printLine(char symbol = '-', short count = 50);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream fin("input.txt");

	int len = 0; //Количество стран, хранящихся в файле
	fin >> len;

	country *countries = new country[len];
	writeCountry(countries, len, fin);
	fin.close();

	long long min, max, tmp;

	// - - - 
	cout << endl << "Все страны в алфавитном порядке: " << endl;

	printLine();

	quickSort(countries, 0, len - 1);
	printCountry(countries, len);

	printLine();

	// - - -
	cout << endl << "Страны, с наcелением от: "; cin >> min;
	cout << "До: "; cin >> max;

	printLine();

	for (int i = 0; i < len; i++) {
		country item = countries[i];

		if (item.population >= min && item.population <= max) {
			countries[i].print();
		}
	}

	printLine();

	// - - -
	cout << endl << "Страны, с населением больше: "; cin >> tmp;
	cout << "И площей от: "; cin >> min;
	cout << "До: "; cin >> max;

	printLine();

	for (int i = 0; i < len; i++) {
		country item = countries[i];

		if (item.population > tmp && item.S >= min && item.S <= max) {
			countries[i].print();
		}
	}

	printLine();

	system("pause");
	return 0;
}

void writeCountry(country *countries, int len, ifstream &fin) {
	for (int i = 0; i < len; i++) {
		countries[i] = {};

		fin >> countries[i].name;
		fin >> countries[i].capital;
		fin >> countries[i].population;
		fin >> countries[i].S;
	}
}

void printCountry(country *countries, int len) {
	for (int i = 0; i < len; i++) {
		countries[i].print();
	}
}

void printLine(char symbol, short count) {
	for (int i = 0; i < count; i++) {
		cout << symbol;
	}

	cout << endl;
}

void quickSort(country *arr, int l, int r) {
	int i = l, j = r;
	string middle = arr[(i + j) / 2].name;

	do {
		while (middle > arr[i].name) i++;
		while (middle < arr[j].name) j--;

		if (i <= j) {
			swap(arr[i], arr[j]);
			i++; j--;
		}

	} while (i < j);

	if (i < r) quickSort(arr, i, r);
	if (j > l) quickSort(arr, l, j);
}
*/