#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	string str;
	cin >> str;

	int b1 = 0;
	int b2 = 0;

	for (auto& c : str) {
		if (c == '(') b1++;
		else if (c == ')') b1--;

		if (c == '[') b1++;
		else if (c == ']') b1--;
	}

	cout << ((b1 == 0 && b2 == 0) ? "Yes" : "No") << endl;

	system("pause");
	return 0;
}