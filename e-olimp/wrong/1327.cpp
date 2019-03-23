#include <iostream>

using namespace std;

// 1327 - реальная задача найти fact(1000)

long long fact(long long n) {
	long long res = 1;

	for (int i = 2; i <= n; i++) {
		res *= i;
	}

	return res;
}

int main() {
	long long n;
	cin >> n;

	cout << fact(n) << endl; 

	system("pause");
	return 0;
}