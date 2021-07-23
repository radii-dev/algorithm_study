#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

int palindrome_matching(char src[8][8], int len) {
	int count = 0, result = 0;
	if ((len % 2) == 1) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < (8 - len + 1); j++) {
				count = 0;
				for (int k = 1; k <= (len / 2); k++) {
					if (src[i][j + len / 2 - k] == src[i][j + len / 2 + k]) count++;
				}
				if (count == len / 2) result++;
				count = 0;
				for (int k = 1; k <= (len / 2); k++) {
					if (src[j + len / 2 - k][i] == src[j + len / 2 + k][i]) count++;
				}
				if (count == len / 2) result++;
			}
		}
	}
	else if ((len % 2) == 0) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < (8 - len + 1); j++) {
				count = 0;
				for (int k = 1; k <= (len / 2); k++) {
					if (src[i][j + len / 2 - k] == src[i][j + len / 2 + k - 1]) count++;
				}
				if (count == len / 2) result++;
				count = 0;
				for (int k = 1; k <= (len / 2); k++) {
					if (src[j + len / 2 - k][i] == src[j + len / 2 + k - 1][i]) count++;
				}
				if (count == len / 2) result++;
			}
		}
	}
	return result;
}

int main() {
	int num = 1;
	for (int i = 0; i < 10; i++) {
		int len = 0;
		char dummy;
		char srcstr[8][8];
		cin >> len;
		for (int j = 0; j < 8; j++) {
			scanf("%c", &dummy);
			for (int k = 0; k < 8; k++) {
				scanf("%c", &srcstr[j][k]);
			}
		}
		int result = palindrome_matching(srcstr, len);
		std::cout << "#" << num++ << " " << result << endl;
	}
}