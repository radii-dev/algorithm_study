#include <iostream>
using namespace std;

int compareInt(int a, int b) {
	int result = 0;
	result = (a > b) ? a : b;
	return result;
}

int main() {
	int length = 0;
	for (int i = 0; i < 10; i++) {
		int count = 0;
		cin >> length;
		int* building = new int[length];
		for (int j = 0; j < length; j++) {
			cin >> building[j];
		}
		for (int j = 2; j < length - 1; j++) {
			if (building[j] > building[j - 2] && building[j] > building[j - 1] && building[j] > building[j + 1] && building[j] > building[j + 2]) {
				count += building[j] - compareInt(compareInt(building[j - 2], building[j - 1]), compareInt(building[j + 1], building[j + 2]));
			}
		}
		cout << "#" << i + 1 << " " << count << endl;
		delete[] building;
	}
}