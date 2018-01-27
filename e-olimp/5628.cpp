#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	short n, res;
	fin >> n;

	//Цифры
	short a = n / 100,
		b = (n / 10) % 10,
		c = n % 10;

	//Сортировка (a < b < c)
	if (a > c) swap(a, c);

	if (b < a) swap(a, b);
	else if (b > c) swap(b, c);

	//Минимальное
	if (a == 0) {
		if (b == 0) res = c*100;
		else res = b*100 + c;
	}
	else {
		res = a*100 + b*10 + c;
	}

	fout << res; 

	fin.close();
	fout.close();
	return 0;
}