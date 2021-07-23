#include <iostream>
#define STU_SIZE 1000
using namespace std;

int main() {
	int T = 0, num = 0;
	int grade[STU_SIZE] = { 0, };
	int mode[10] = { 0, };
	cin >> T;
	for (int i = 0; i < T; i++) {
		int count[101] = { 0, };
		int value = 0;
		cin >> num;
		for (int j = 0; j < STU_SIZE; j++) {
			cin >> grade[j];
			count[grade[j]]++;
		}
/*
		for (int j = 0; j < 499; j++) {
			for (int k = 0; k < 101; k++) {
				if (count[k] > 0) {
					count[k]--;
					break;
				}
			}
			for (int k = 101; k > 0; k--) {
				if (count[k] > 0) {
					count[k]--;
					break;
				}
			}
		}
*/
		for (int j = 0; j < 101; j++) {
			if (count[j] >= value) {
				mode[i] = j;
				value = count[j];
			}
		}
		cout << "#" << i + 1 << " " << mode[i] << endl;
	}
}	