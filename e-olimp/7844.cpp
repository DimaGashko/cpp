#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n - 1; i++) {
		if (arr[i] < 0 && arr[i + 1] < 0 || arr[i] > 0 && arr[i + 1] > 0) {
			cout << arr[i] << " " << arr[i + 1] << endl;
		}
	}

	system("pause");
	return 0;
}