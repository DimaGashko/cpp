#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string sNum;
	cin >> sNum;

	vector<int> digits(sNum.size());

	transform(sNum.begin(), sNum.end(), digits.begin(), [](char c) {
		return c - '0';
	});

	digits.erase(std::min_element(digits.begin(), digits.end()));

	for (auto& d : digits) {
		cout << d;
	}

	cout << endl;

	system("pause");
	return 0;
}