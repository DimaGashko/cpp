#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Num {
public:
	Num() {
	
	}

	Num(string str) {
		string revStr = str;
		reverse(revStr.begin(), revStr.end());
		int size = revStr.size();

		number = vector<int>(size);

		for (int i = 0; i < size; i++) {
			number[i] = revStr[i] == '1' ? 1 : 0;
		}

		optimize();
	}

	int get(int index) {
		if (index >= (int)number.size()) return 0;

		return number[index];
	}

	void set(int value, int index) {
		if (index >= (int)number.size()) {
			number.push_back(value);
		}

		number[index] = value;
	}

	void addToItem(int value, int index) {
		set(get(index) + value, index);
	}

	Num add(Num num) {
		int size = max(number.size(), num.number.size());
		Num res;

		for (int i = 0; i < size; i++) {
			int sum = get(i) + num.get(i);

			res.addToItem(sum % 2, i);
			num.addToItem(sum / 2, i + 1);
		}

		res.addToItem(num.get(size), size);
		
		res.optimize();

		return res;
	}

	void optimize() {
		for (int i = number.size() - 1; i >= 1 && number[i] == 0; i--) {
			number.pop_back();
		}
	}

	string toString() {
		string res;

		for (int i = (int)number.size() - 1; i >= 0; i--) {
			res += to_string(number[i]);
		}

		return res;
	}

private:
	vector<int> number;

};

int main() {
	string strNum1, strNum2;
	cin >> strNum1 >> strNum2;

	Num a(strNum1);
	Num b(strNum2);

	Num res = a.add(b);

	cout << res.toString() << endl;

	system("pause");
	return 0;
}