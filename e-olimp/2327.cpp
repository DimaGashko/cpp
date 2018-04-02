#include <iostream>
#include <string>
#include <fstream>
 
using namespace std;

void counting_sort(int* vec, unsigned int len, int min, int max) {
 	int *cnt = new int[max-min+1];
 
 	for (int i = min; i <= max; ++i)
 		cnt[i - min] = 0;
 
 	for (int i = 0; i < len; ++i)
 		++cnt[vec[i] - min];
 
 	for (int i = min; i <= max; ++i)
 		for(int j = cnt[i - min]; j--;)
 			*vec++ = i;
 
 	delete [] cnt;
 }

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n, tmp;
	fin >> n;

	int *ns = new int[n];
	
	for (int i = 0; i < n; i++) {
		fin >> ns[i];
	}
	
	counting_sort(ns, n, 0, 100000);

	for (int i = 0; i < n; i++) {
		fout << ns[i] << ' ';
	}
	
	return 0;
}