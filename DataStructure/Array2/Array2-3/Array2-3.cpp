#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Coordinate {
public:
	int x = 0;
	int y = 0;
};

int detect(vector< vector<int> > ladder, Coordinate coord) {
	int count = 0;
	for (int i = 0; i < 100; i++) {
		if (ladder[coord.x][coord.y - 1] == 1) {
			while (ladder[coord.x][coord.y - 1] == 1) {
				coord.y -= 1;
				count++;
			}
		}
		else if (ladder[coord.x][coord.y + 1] == 1) {
			while (ladder[coord.x][coord.y + 1] == 1) {
				coord.y += 1;
				count++;
			}
		}
		coord.x++;
		count++;
	}
	return count;
}

int main() {
	for (int i = 0; i < 10; i++) {
		Coordinate coord;
		int num = 0, resulty = 0, count = 0;
		int precount = 99 * 9 + 99;
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
		for (int j = 0; j < 100; j++) {
			if (ladder[0][j] == 1) {
				coord.y = j;
				count = detect(ladder, coord);
				if (count <= precount) {
					precount = count;
					resulty = j;
				}
			}
		}
		cout << "#" << num << " " << resulty << endl;
	}
}