#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

bool isIdeal(int n) {
	//Прекалк :)
	switch (n) {
		case 6: case 28: case 496: case 8128: case 33550336: return true;
	}

	return false;
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int m, n;
	bool find = 0;
	fin >> m >> n;

	for (int i = m; i <= n; i++) {
		if (!isIdeal(i)) continue; 

		find = true;
		fout << i << endl;
	}

	if (!find) fout << "Absent";

	fin.close();
	fout.close();
	return 0;
}