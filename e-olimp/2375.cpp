#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
	int n, cost, S;
	string type;
	
	double allS = 0, roomsS = 0, balconyS = 0;

	fin >> n >> cost;

	for (int i = 0; i < n; i++) {
		fin >> S >> type;

		allS += S;
		
		if (type == "bedroom") roomsS += S;
		else if (type == "balcony") balconyS += S;
	}

	double res = (allS - balconyS / 2) * cost;

	fout << fixed << setprecision(1)
		<< allS << endl
		<< roomsS << endl
		<< res;

	fin.close();
	fout.close();
	return 0;
}