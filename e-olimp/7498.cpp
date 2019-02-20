// https://www.e-olymp.com/ru/submissions/5114556

#include <iostream>
#include <cmath>

using namespace std;

int main() {

	int x1, y1, x2, y2, x3, y3, x4, y4, w, h;
	int pl, pt, pr, pb, fullW, fullH;

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> w >> h;

	pl = abs(x3 - x1);
	pt = abs(y2 - y4);
	pr = abs(x2 - x4);
	pb = abs(y3 - y1);
	fullW = abs(x2 - x1);
	fullH = abs(y2 - y1);

	bool ok = w <= fullW && h <= fullH && (w <= pl || w <= pr || h <= pt || h <= pb);

	cout << (ok ? "Yes" : "No") << endl;

	system("pause");
	return 0;
}
