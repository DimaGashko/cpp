#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int ax, ay, x1, y1, x2, y2;
	double S = 0;

	cin >> ax >> ay;
	x1 = ax; y1 = ay;

	for (int i = 1; i < n; i++) {
		cin >> x2 >> y2;

		S += x1*y2 - y1*x2;

		x1 = x2; y1 = y2;
	}

	x2 = ax; y2 = ay;
	S += x1*y2 - y1*x2;
	S /= 2;

	cout << (S > 0 ? S : -S);

	return 0;
}