#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

int palindrome_matching(char src[100][100], int len) {
	int count = 0, result = 0;
	if ((len % 2) == 1) {
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < (100 - len + 1); j++) {
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
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < (100 - len + 1); j++) {
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

int palindrome_maxlen(char src[100][100]) {
	int max = 0, count = 0;
	int maxlen = 100;
	while (max == 0) {
		max = palindrome_matching(src, maxlen--);
		count++;
	}
	return (100 - count + 1);
}

int main() {
	int num = 0;
	for (int i = 0; i < 10; i++) {
		int len = 0;
		char dummy;
		char srcstr[100][100];
		cin >> num;
		for (int j = 0; j < 100; j++) {
			scanf("%c", &dummy);
			for (int k = 0; k < 100; k++) {
				scanf("%c", &srcstr[j][k]);
			}
		}
		int result = palindrome_maxlen(srcstr);
		std::cout << "#" << num << " " << result << endl;
	}
}