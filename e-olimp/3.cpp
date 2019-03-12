#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long num;

num getMinOfMatches(num n) {
	num a = (num)cbrt(n);
	n -= a * a * a;

	num res = ((a + 1) * (a + 1) * a * 3);
	if (n == 0) return res;

	num squares12 = min(n / (a * a), (num)2);
	res += (3 * a * a + 4 * a + 1) * squares12;
	n -= a * a * squares12;
	if (n == 0) return res;

	if (squares12 > 1) {
		num p = min(n, a);
		res += (p - 1) * 3 + 5;
		n -= p;
		if (n == 0) return res;
	}

	num squares3 = min(n / (a * a), (num)1);
	res += (3 * a * a + 4 * a + 1) * squares3;
	n -= a * a * squares3;
	if (n == 0) return res;

	if (squares12 + squares3 < 3) {
		num b = (num)sqrt(n);
		n -= b * b;
		res += 3 * b * b + 4 * b + 1;
		if (n == 0) return res;

		num twos = (n - 1) / b + 1;
		res += (n - twos) * 3 + twos * 5;
	}
	else {
		num twos = (n - 1) / a + 1;
		res += (n - twos) * 3 + twos * 5;
	} 

	return res;
}

int main() {
	num n;
	cin >> n;
	cout << getMinOfMatches(n) << endl;

	system("pause");
	return 0;
}