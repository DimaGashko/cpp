#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

map<char, char> coBrackets { 
	{'(', ')'},
	{'[', ']'},
	{'{', '}'},
};

bool validate(string str) {
	stack<char> seq;

	for (auto& c : str) {
		if (c == '(' || c == '[' || c == '{') {
			seq.push(c);
		}

		else if (c == ')' || c == ']' || c == '}') {
			if (seq.empty()) return 0;
			if (coBrackets[seq.top()] != c) return 0;
			seq.pop();
		}
	}

	return seq.empty();
}

int main() {
	string str;
	cin >> str;

	cout << (validate(str) ? "yes" : "no") << endl;
	
	system("pause");
	return 0;
}