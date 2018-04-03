#include <iostream>
#include <fstream>
 
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int get(int ignore = 1) {
	int r; char tmp;
	fin >> r;
	if (ignore) fin >> tmp;
	return r;
}

int main() {
	int h1 = get(), m1 = get(), s1 = get(0), h2 = get(), m2 = get(), s2 = get();
	int time1, time2, res;

	time1 = h1 * 60 * 60 + m1 * 60 + s1;
	time2 = h2 * 60 * 60 + m2 * 60 + s1;

	res = time2 - time1;


	return 0;
}