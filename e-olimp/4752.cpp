#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int n, m, count = 0;
	cin >> n >> m;
	
	for (int i = n * m; i >= 0; i--) {
		if ((i / m == i % n) && (i % m == i / n)) count++;
	}

	cout << count;
	return 0;
}