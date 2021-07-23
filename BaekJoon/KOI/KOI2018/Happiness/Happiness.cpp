#include <iostream>
#include <vector>

using namespace std;

int max_Deviation(vector<int> src) {
	int max = 0;
	int min = 100;
	for (int i = 0; i < src.size(); i++) {
		if (src.at(i) > max)
			max = src.at(i);
		if (src.at(i) < min)
			min = src.at(i);
	}
	return max - min;
}

int main() {
	int len = 0, tmp = 0;
	vector<int> score;
	cin >> len;
	
	for (int i = 0; i < len; i++) {
		cin >> tmp;
		score.push_back(tmp);
	}

	cout << max_Deviation(score);
}