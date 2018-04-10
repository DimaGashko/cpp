#pragma once

#ifndef FUNCTIONS_H
#define FUNCTIONS_H 

#include <string>

using namespace std;

struct country {
	string name;
	string capital;
	long long population;
	int S;
};

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


//Вставляет элемент списка в список 
//После первого элемента, что меньше этого
//(елси для добавления использовать только 
//эту функцию, то элементы будут отсортированы)
void insertSortToList(List<country*> *countries, country *next) {
	if (!countries->first()) {
		countries->push(next);
	}
	else {
		countries->forEach([&countries, &next](auto *item) -> bool {
			if (!item->next || item->next->val->name > next->name) {
				countries->insertAfter(item, next);
				return false;
			}

			return true;
		}, countries->head);
	}
}

/**
* Считывает странны из файла, и возвращает указатель на список указателей на странны
* @param {string} adressDB - пусть к файлу со странами
*/
auto getCountriesFromFile(string adressDB) {
	ifstream fin(adressDB);
	auto *countries = getList<country*>();

	country *next = NULL;

	while (enterCountryFromFile(next, fin)) {
		insertSortToList(countries, next);
	}

	fin.close();
	return countries;
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

//Выводит в консоль список команд
void printCommand() {
	/*#ifndef IS_DEV
	cout << "(Версия для разработки)" << endl << endl;
	#endif*/

	cout << "Выберите команду: " << endl
		<< "1. Вывести все страны" << endl
		<< "2. Вывести страны с населением от min до max" << endl
		<< "3. Вывести страны с площей от min до max и населением больше n" << endl
		<< "4. Добавить страну" << endl
		<< endl
		<< "5. Очистить экран" << endl
		<< "0. Выход" << endl << endl;
}

// - - - Menu - - -
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


#endif //FUNCTIONS_H