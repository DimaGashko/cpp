#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int getNumber(const char label[]);
string getBin(long long n);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	 
	while (1) {
		int n = getNumber("Введите n: ");
		long long res = long long(1) << n;

		cout << "pow(2, " << n << "):" << endl
			<< "\t" << getBin(res) << " - в 2-ичной СК" << endl
			<< "\t" << oct << res << " - в 8-ричной СК" << endl
			<< "\t" << dec << res << " - в 10-ичной СК" << endl
			<< "\t" << hex << res << " - в 16-ричной СК " << endl;
	}

	system("pause");
	return 0;
}

string getBin(long long n) {
	string bin;

	while (n) {
		bin += to_string(n % 2);
		n /= 2;
		
	}

	reverse(bin.begin(), bin.end());
	return bin;
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