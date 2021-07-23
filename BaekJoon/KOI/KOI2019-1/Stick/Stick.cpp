#include <iostream>
#include <vector>

using namespace std;

int stick(int len) {
	vector<int> see;
	int tmp;
	for (int i = 0; i < len; i++) {
		cin >> tmp;
		if (!see.empty()) {
			int j = see.size() - 1;
			while (j >= 0 && see.at(j--) <= tmp)
				see.pop_back();
		}
		see.push_back(tmp);
	}
	return see.size();
}

int main() {
	int len;
	cin >> len;

	cout << stick(len);
}