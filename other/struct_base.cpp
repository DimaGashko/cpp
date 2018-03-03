#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct student {
	string name = "Anonim";
	short age = 18;

	string job = "hidden";

	student* bestBriend;
};

int main() {
	SetConsoleOutputCP(1251);

	student a = {"Andrey"},
		b = { "Bob" },
		c = { "Candy" };

	a.bestBriend = &b;
	b.bestBriend = &c;
	c.bestBriend = &a;

	cout << "Лучший друг " << a.name << ": " << a.bestBriend->name << endl;
	cout << "А лучшний друг " << a.bestBriend->name << ": " << a.bestBriend->bestBriend->name << endl;
	cout << endl << "But sizeOf(student): " << sizeof(student) << endl;

	system("pause");
	return 0;
}