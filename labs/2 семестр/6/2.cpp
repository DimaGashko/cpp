#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

//Эллемент однонаправленного списка
template <typename T>
struct ListItem {
	T val = NULL;
	ListItem *next = NULL;
};

//Однонаправленный список
template<typename T>
struct List {
	ListItem<T> *head, *end;

	//Добавляет элемента в конец списка
	void push(T n) {
		end = end->next = new ListItem<T>;
		end->val = n;
	}

	//Добавляет элемент после указанного элемента
	void insertAfter(ListItem<T> *item, T n) {
		ListItem<T> *added = new ListItem<T>;
		added->val = n;

		added->next = item->next;
		item->next = added;
	};

	//Возвращает ссылку на первый реальный элемент
	ListItem<T>* first() {
		return head->next;
	}

	//Иницилизирует список
	List* init() {
		end = (head = new ListItem<T>);
		head->next = end;

		return this;
	}
};

//Возвращает однонаправленный список
//Пример исопльзования:
//List<int> *list = getList<int>();
template<typename T>
List<T>* getList() {
	return (new List<T>)->init();
}

struct country {
	string name;
	string capital;
	long long population;
	int S;

	string toString() {
		return name + "("
			+ "столица: " + capital
			+ "; население: " + to_string(population)
			+ "; площадь: " + to_string(S) + " кв. км)\n";
	}
};

template <typename T>
T prompt(const char label[] = "Введите значение: ");

void printCommand();

void add() {
	cout << "add\n";
}

void printAll(List<country*>* countries) {
	ListItem<country*> *cur = countries->first();

	while (cur) {
		cout << (cur->val->toString());
		cur = cur->next;
	}
}

void printByPopul() {
	cout << "byPopul\n";
}

void printBySAndPolul() {
	cout << "bySAndPopul\n";
}

void clearConsole() {
	system("cls");
	printCommand();
}

/**
* Вводит данные из файла в country
* Возвращает true - если удалось испешно
* @param{country *&item} - country, в которую нужно записать данные
*/
bool enterCountryFromFile(country *&item, ifstream &fin) {
	item = new country;

	return !!(
		fin >> item->name
		>> item->capital
		>> item->population
		>> item->S
		);
}

/**
* Считывает странны из файла, и возвращает указатель на список указателей на странны
* @param {string} adressDB - пусть к файлу со странами
*/
List<country*>* getCountriesFromFile(string adressDB) {
	ifstream fin(adressDB);
	List<country*> *countries = getList<country*>();

	country *next = NULL;

	while (enterCountryFromFile(next, fin)) {
		countries->push(next);
	}

	fin.close();
	return countries;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string adressDB = "input.txt";

	List<country*> *countries = getCountriesFromFile(adressDB);

	printCommand();

	bool exit = false;

	while (true) {
		switch (prompt<short int>("> ")) {

		case 1:
			add();
			break;

		case 2:
			printAll(countries);
			break;

		case 3:
			printByPopul();
			break;

		case 4:
			printBySAndPolul();
			break;

		case 5:
			clearConsole();
			break;

		case 0:
			exit = true;
			break;

		default:
			cout << "Неправильная команда" << endl;
			break;
		}

		if (exit) break;
		cout << endl;
	}

	return 0;
}

//Выводит в консоль список команд
void printCommand() {
	cout << "Выберите команду: " << endl
		<< "1. Добавить запись в файл" << endl
		<< "2. Вывести все страны" << endl
		<< "3. Вывести страны с населением от min до max" << endl
		<< "4. Вывести страны с площей от min до max и населением боьше n" << endl
		<< endl
		<< "5. Очистить экран" << endl
		<< "0. Выход" << endl << endl;
}


/**
* Запрашивает от пользователя значение нужного типа
* @param{char[]} label - текст, предложенный пользователю
*
* Привет работы:
* prompt<int>("Введите целое число: ");
* prompt<char>("Введите символ: ");
* prompt<string>("Введите строку: ");
*/
template <typename T>
T prompt(const char label[]) {
	cout << label;

	while (true) {
		T val;
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







/*#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

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