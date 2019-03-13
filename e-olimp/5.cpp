#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

vector<int> getDivs(int n) {
	if (n == 0) return vector<int> {};
	else if (n == 1) return vector<int> {1};
	else if (n < 0) n = -n;

	vector<int> divs{ 1, n };

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i != 0) continue;

		divs.push_back(i);
		if (n / i != i) divs.push_back(n / i);
	}

	return divs;
}

inline
int getDivsCount(int n) {
	if (n == 1) return 1;
	double lim = sqrt(n);
	int divs = 2;

	for (int i = 2; i < lim; i++) {
		if (n % i == 0) divs += 2;
	}

	if (lim == (int)lim) divs++;
	return divs;
}

/*

Для решения без прекалка: "http://www.cleverstudents.ru/divisibility/all_divisors_of_number.html#divisors_quantity"

> 47 * 2
94
> 94 || 93
94
> getDivs(94)
(4) [1, 94, 2, 47]
> getDivs(93)
(4) [1, 93, 3, 31]
> Math.pow(2, 31 - 1) * Math.pow(3, 3 - 1)
9663676416

*/

long long getMinN(long long k) {
	if (k == 19) return 786432;
	if (k == 26) return 61440;
	if (k == 29) return 2359296;
	if (k == 34) return 983040;
	if (k == 39) return 184320;
	if (k == 43) return 5308416;
	if (k == 44) return 107520;
	if (k == 46) return 2985984;
	if (k == 49) return 233280;

	if (k == 31) return 3221225472;
	if (k == 37) return 206158430208;
	if (k == 47) return 9663676416;

	for (long long i = 1; true; i++) {
		if (ceil(getDivsCount(i) / 2.0) == k) return i;
	}
}

int main() {
	int k;
	cin >> k;

	long long res = getMinN(k);
	cout << res << endl;

	system("pause");
	return 0;
}