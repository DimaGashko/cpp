#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct Point {
	double x, y;
};

int main() {
	vector<Point> coords;

	Point tmp;

	while (fin >> tmp.x && fin >> tmp.y) {
		coords.push_back(Point(tmp));
	}

	sort(coords.begin(), coords.end(), [](Point a, Point b) {
		double aw = a.x + a.y;
		double bw = b.x + b.y;

		if (aw == bw) {
			return a.x < b.x;
		}

		return aw < bw;
	});

	for (auto& coord : coords) {
		fout << coord.x << " " << coord.y << endl;
	}

	return 0;
}