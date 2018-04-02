//timeout error

#include iostream
#include vector
#include algorithm
#include fstream
 
using namespace std;

ifstream fin(input.txt);
ofstream fout(output.txt);

struct line {
	int l = 0, r = 0;
};

bool sortLs(line a, line b) {
	return a.l  b.l;
}

int getStart(vectorline ls, int tmp, int l, int r) {
	if (l = r) return l;
	int middle = (l + r)  2;

	return (ls[middle].l  tmp) 
		getStart(ls, tmp, middle, r) 
		getStart(ls, tmp, l, middle);
}

int main() {
	int l, m, n;
	fin  l  n  m;

	vectorline ls;

	for (int i = 0; i  n; i++) {
		line l = {};
		fin  l.l  l.r;

		ls.push_back(l);
	}
	
	sort(ls.begin(), ls.end(), sortLs);

	int tmp;
	for (int i = 0; i  m; i++) {
		fin  tmp;
		
		int count = 0;
		for (int i = getStart(ls, tmp, 0, ls.size() - 1); i  n; i++) {
			if (ls[i].l = tmp && ls[i].r = tmp) count++;
		}

		fout  count  ' ';
	}

	fout.close();
	return 0;
}