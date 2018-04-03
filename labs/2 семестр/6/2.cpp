#include <iostream>
#include <iomanip>
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
		ListItem<T> *item = new ListItem<T>;
		item->val = n;
		end->next = item;

		end = item;
	}

	//Добавляет элемент после указанного элемента
	void insertAfter(ListItem<T> *prev, T n) {
		ListItem<T> *item = new ListItem<T>;
		item->val = n;
		item->next = prev->next;

		prev->next = item;
	};

	template<typename _Fn>
	void forEach(_Fn func, ListItem<T> *cur = NULL) {
		if (!cur) cur = first();

		while (cur) {
			bool answer = func(cur);
			if (!answer) return;

			cur = cur->next;
		}
	}

	//Возвращает ссылку на первый реальный элемент
	ListItem<T>* first() {
		return head->next;
	}

	//Иницилизирует список
	List* init() {
		head = new ListItem<T>;
		head->next = NULL;

		end = head;

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

//Вставляет элемент списка в список 
//После первого элемента, что меньше этого
//(елси для добавления использовать только 
//эту функцию, то элементы будут отсортированы)
void insertSortToList(List<country*> *countries, country *next) {
	countries->push(next);
}

void printHeader() {
	cout << "+-----------------+-----------------+-----------------+-----------------+" << endl
		<< "| Страна          | Столица         | Население       | Площадь         |" << endl
		<< "+=================+=================+=================+=================+" << endl;
}

void printCountry(country *c) {
	cout << left << "| " << setw(15) << c->name
		<< " | " << setw(15) << c->capital
		<< " | " << setw(15) << c->population
		<< " | " << setw(15) << c->S << " |" << endl;
	cout << "+-----------------+-----------------+-----------------+-----------------+" << endl;
}

void add(List<country*>* countries, string adressDB) {
	country *added = new country;

	added->name = prompt<string>("Имя: ");
	added->capital = prompt<string>("Столица: ");
	added->population = prompt<long long>("Население: ");
	added->S = prompt<int>("Площадь: ");

	insertSortToList(countries, added);

	ofstream fout(adressDB, ios_base::app);
	fout << endl <<
		added->name << ' ' <<
		added->capital << ' ' <<
		added->population << ' ' <<
		added->S;
	fout.close();
}

void printAll(List<country*>* countries) {
	cout << "Все страны: " << endl;
	printHeader();

	countries->forEach([](auto *item) -> bool {
		printCountry(item->val);
		return true;
	});
}

void printByPopul(List<country*> *countries) {
	cout << "Страны с населением" << endl;

	long long min = prompt<long long>("От: "),
		max = prompt<long long>("До: ");

	if (min > max) swap(min, max);
	printHeader();

	countries->forEach([min, max](auto *item) -> bool {
		long long popul = item->val->population;

		if (popul >= min && popul <= max) {
			printCountry(item->val);
		}

		return true;
	});
}

void printBySAndPolul(List<country*> *countries) {
	long long popul = prompt<long long>("Страны с населением больше: ");
	int minS = prompt<int>("И площей от: ");
	int maxS = prompt<int>("До: ");

	if (minS > maxS) swap(minS, maxS);
	printHeader();

	countries->forEach([popul, minS, maxS](auto *item) -> bool {
		int S = item->val->S;

		if (S >= minS && S <= maxS && item->val->population >= popul) {
			printCountry(item->val);
		}

		return true;
	});
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
		insertSortToList(countries, next);
	}

	fin.close();
	return countries;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string adressDB = "input.txt";
	auto *countries = getCountriesFromFile(adressDB);

	printCommand();

	while (true) {
		switch (prompt<short int>("> ")) {

		case 1:
			add(countries, adressDB);
			break;

		case 2:
			printAll(countries);
			break;

		case 3:
			printByPopul(countries);
			break;

		case 4:
			printBySAndPolul(countries);
			break;

		case 5:
			clearConsole();
			break;

		case 0:
			return 0;
			break;

		default:
			cout << "Неправильная команда" << endl;
			break;
		}

		cout << endl;
	}

	return 0;
}

//Выводит в консоль список команд
void printCommand() {
	cout << "Выберите команду: " << endl
		<< "1. Добавить страну" << endl
		<< "2. Вывести все страны" << endl
		<< "3. Вывести страны с населением от min до max" << endl
		<< "4. Вывести страны с площей от min до max и населением больше n" << endl
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