#include <iostream>
#include <windows.h>

using namespace std;

int getN(int n) {
	if (n <= 0)	return 0;
	else return 3 * getN(n - 1) + 1;
}

int getNumber(const char label[]);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (1) {
		int n = getNumber("Введите номер элемента последовательности: ");
		cout << "x[" << n << "] = " << getN(n) << endl;
	}

	return 0;
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

