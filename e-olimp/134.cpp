#include <iostream>
#include <string>

using namespace std;

int sumDigit(string s) {
	int sum = 0;
	
	for (int i = s.length() - 1; i >= 0; i--) {
		sum += s[i] - '0';
	}

	return sum;
}

int main() {
	string s;
	cin >> s;

	cout << (sumDigit(s) % 3 == 0 ? "YES" : "NO");

	return 0;
}