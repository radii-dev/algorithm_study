#include <iostream>
using namespace std;

int square(int base, int index) {
	index--;
	if (index) return base * square(base, index);
}

int main() {
	int num = 0;
	for (int i = 0; i < 10; i++) {
		int base = 0, index = 0;
		cin >> num;
		cin >> base;
		cin >> index;

		int result = square(base, index);
		std::cout << "#" << num << " " << result << endl;
	}
}