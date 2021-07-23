#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Coordinate {
public:
	int x = 99;
	int y = 0;

};

Coordinate detect(vector< vector<int> > ladder, Coordinate coord) {
	for (int i = coord.x; i >= 0; i--) {
		if (ladder[coord.x][coord.y - 1] == 1) {
			while (ladder[coord.x][coord.y - 1] == 1) {
				coord.y -= 1;
			}
		}
		else if (ladder[coord.x][coord.y + 1] == 1) {
			while (ladder[coord.x][coord.y + 1] == 1) {
				coord.y += 1;
			}
		}
		coord.x--;
	}
	return coord;
}

int main() {
	for (int i = 0; i < 10; i++) {
		Coordinate coord;
		int num = 0;
		cin >> num;
		vector< vector<int> > ladder;
		for (int j = 0; j < 100; j++) {
			vector<int> elem(100);
			ladder.push_back(elem);
		}
		for (int j = 0; j < 100; j++) {
			for (int k = 0; k < 100; k++) {
				cin >> ladder[j][k];
			}
		}
		for (int j = 0; j < 100; j++) if (ladder[99][j] == 2) coord.y = j;
		coord = detect(ladder, coord);
		cout << "#" << num << " " << coord.y << endl;
	}
}