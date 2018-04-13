#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool ready = false;

void find(vector<int> &s, int n, int d, int h) {
	if (ready) return;

	s.push_back(d);
	n -= d;
	h--;

	if (n == 0 && h == 0) {
		ready = true;
		return;
	} 

	if ((n <= 0 && h > 0) || (h <= 0 && n > 0) || (n <= 0 && h <= 0)) {
		s.pop_back();
		s.pop_back();
		return;
	}

	find(s, n, d + 1, h);
	if (d > 1) find(s, n, d - 1, h);
}

int main() {
	int n, d, h;
	cin >> n >> d >> h;

	vector<int> s;

	find(s, n, d, h);

	
		for (int i = 0; i < s.size(); i++) {
			cout << s[i] << endl;
		}
	

	system("pause");
	return 0;
}