#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> getPrimes(int n) {
	vector<bool> numbers(n - 2); // 1 - не простое, каждый индек - на два меньше
	int p = 2;

	for (int p = 2; p * p <= n; p++) {

		for (int i = 2 * p; i < n; i += p) {
			numbers[i - 2] = true;
		}
	}

	vector<int> primes;

	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i]) continue;
		primes.push_back(i + 2);
	}

	return primes;
}

bool hasItem(vector<int> arr, int item, int l, int r) {
	if (l >= r) return arr[l] == item;

	int middle = (l + r) / 2;

	if (arr[middle] > item) return hasItem(arr, item, l, middle - 1);
	if (arr[middle] < item) return hasItem(arr, item, middle + 1, r);
	if (arr[middle] == item) return true;
}

int getReversed(int n) {
	string reversed = to_string(n);
	reverse(reversed.begin(), reversed.end());

	return atoi(reversed.c_str());
}

int main() {
	int a, b;
	cin >> a >> b;

	auto primes = getPrimes(10000);
	int mirrorPrimesCount = 0;
	int primesSize = primes.size();

	for (auto item : primes) {
		if (item < a) continue;
		if (item > b) break;
	
		if (hasItem(primes, getReversed(item), 0, primesSize - 1)) {
			mirrorPrimesCount++;
		}
	}

	cout << mirrorPrimesCount << endl;

	system("pause");
	return 0;
}