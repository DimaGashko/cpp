#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>

using namespace std;

string rev(string &str) {
	string rev = str;
	reverse(rev.begin(), rev.end());
	long long n = atoll(rev.c_str());

	return to_string(n);
}

int getLevel(long long n) {
	for (long long level = 0; ; level++) {
		string s = to_string(n);
		string sRev = rev(s);

		if (sRev == s) {
			return level;
		}

		n = n + atoll(sRev.c_str());
	}
}

int main() {
	long long n;
	cin >> n;

	cout << getLevel(n) << endl;

	system("pause");
	return 0;
}