#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

template <typename T>
struct ListItem {
	T val = NULL;
	ListItem *next = NULL;
};

template<typename T>
struct List {
	ListItem<T> *head, *end;

	void add(T n) {
		end->val = n;
		end = end->next = new ListItem<T>;
	}

	ListItem<T>* first() {
		return head->next;
	}

	List* init() {
		(head = new ListItem<T>)->next = (end = new ListItem<T>);
		return this;
	}
};

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

void printAll() {
	cout << "print\n";
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

bool enterCountryFromFile(country *&item, ifstream &fin) {
	item = new country;

	return !!(
		fin >> item->name 
			>> item->capital 
			>> item->population 
			>> item->S
	);
}

List<country*>* getCountriesFromFile(string adressDB) {
	ifstream fin(adressDB);
	List<country*> *countries = getList<country*>();
	
	country *next = NULL;

	while (enterCountryFromFile(next, fin)) {
		countries->add(next);
	}

	fin.close();
	return countries;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	string adressDB = "input.txt";

	List<country*> *countryes = getCountriesFromFile(adressDB);

	ListItem<country*> *cur = countryes->first();
	while (cur->next) {
		//cout << (cur->val->toString());
		cur = cur->next;
	}

	printCommand();

	bool exit = false;

	while (true) {
		switch (prompt<short int>("> ")) {
		
		case 1: 
			add();
			break;

		case 2: 
			printAll();
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






























































#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

void printLine(char symbol = '-', short count = 20) {
	for (int i = 0; i < count; i++) {
		cout << symbol;
	}

	cout << endl;
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