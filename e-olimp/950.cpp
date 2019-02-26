#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int a, b, x1, y1;
	cin >> a >> b >> x1 >> y1;

	float s1 = abs(b * a);
	float s2 = abs((y1 - b) * a);
	float s3 = abs((y1 - b) * (x1 - a));
	float s4 = abs(b * (x1 - a));

	printf("%.3f %.3f %.3f %.3f\n", s1, s2, s3, s4);

	system("pause");
	return 0;
}