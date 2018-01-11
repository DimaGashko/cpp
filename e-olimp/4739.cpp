#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int a, b;
	string res;

	fin >> a >> b;

	bool *all = new bool[b + 1];
	for (int i = 2; i <= b; i++) {
		all[i] = 1;
	}
	
	int sn = sqrt(b) + 1, p;

	for (p = 2; p < sn; p++) {
		if (all[p] == 0) continue;
		    
		for (int i = 2, no = 0; ; i++) {
			no = i * p;
			if (no > b) break;

			all[no] = 0;
		}    
	}

	for (int i = a; i <= b; i++) {
		if (all[i] == 1) res += to_string(i) + ' ';
	}
	
	fout << res;

	delete[] all;

	fin.close();
	fout.close();
	return 0;
}