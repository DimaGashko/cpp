#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
const int N = 10;

struct myType {
	char fff[20];  char aaa[20]; int b; int c;
};
void printStruct(myType st[], int n) {
	for (int i = 0; i < n; i++) {
		cout << " fff: " << st[i].fff << " aaa: " << st[i].aaa;
		cout << " b : " << st[i].b << " c : " << st[i].c << endl;
	}
}
int main() {
	myType st[] = {
		{ "assdss",	"ssdhshf",4,	4.5 },
	{ "jherhhgb",	"xczvfdg",9,	2.4 },
	{ "xcvfd",	"hhgeryt",5,	4.1 },
	{ "jrhjdfd",	"tyyyyy",7,	3.5 }
	};

	printStruct(st, N);

	double k = 0;
	char c = 'd';

	for (int i = 0; i < N; i++) {
		if (strchr(st[i].fff, c)) k++;
		//Увеличивание k, если в fff какой-то структуры находится 'd'
		//(в первых N структурах)
	}
	system("pause");
	return 0;
}