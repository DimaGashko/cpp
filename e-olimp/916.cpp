#include <iostream>
#include <set>

using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if (a > b) swap(a, b);
	if (c > d) swap(c, d);

	set<int> muls;

	for (int i = a; i <= b; i++) {
		for (int j = c; j <= d; j++) {
			muls.insert(i * j);
		}
	}

	cout << muls.size() << endl;

	system("pause");
	return 0;
}