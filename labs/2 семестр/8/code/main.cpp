#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <windows.h>

#include "List.h"
#include "functions.h"

using namespace std;

//#define IS_DEV

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	string adressDB = "input.txt";
	auto *countries = getCountriesFromFile(adressDB);

	printCommand();

	while (true) {
		short n = prompt<short int>("> ");

		if (n == 1) printAll(countries);
		else if (n == 2) printByPopul(countries);
		else if (n == 3) printBySAndPolul(countries);
		else if (n == 4) add(countries, adressDB);

		else if (n == 5) clearConsole();

		else if (n == 0) {
			exit();
			break;
		}

		else cout << "Неправильная команда" << endl;

		cout << endl;
	}

	return 0;
}