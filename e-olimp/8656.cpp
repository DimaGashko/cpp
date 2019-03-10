#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct Point {
	double x, y;
};

int main() {
	vector<Point> coords;
	Point p;

	while (fin >> p.x && fin >> p.y) {
		Point point = p;
		coords.push_back(point);
	}

	sort(coords.begin(), coords.end(), [](Point a, Point b) {
		if (a.x != b.x) return a.x < b.x;
		else return a.y > b.y;
	});

	for (auto& coord : coords) {
		fout << coord.x << " " << coord.y << endl;
	}

	system("pause");
	return 0;
}