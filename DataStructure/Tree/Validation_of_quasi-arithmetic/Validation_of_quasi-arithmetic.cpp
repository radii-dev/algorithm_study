#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
using namespace std;

struct map_pair {
	int key;
	char val;
	int lkey = 0;
	int rkey = 0;
};

bool isSubnum(vector<map_pair>* mp, int len) {
	for (int i = 0; i <= len / 2 - 1; i++)
		if (mp->at(i).val >= '0' && mp->at(i).val <= '9') return true;
	return false;
}

bool isLeafop(vector<map_pair>* mp, int len) {
	for (int i = len / 2 + 1 - 1; i < len - 1; i++) 
		if (mp->at(i).val < '0' || mp->at(i).val > '9') return true;
	return false;
}

bool isOnlylkey(int len) {
	if (len % 2 == 0) return true;
	return false;
}

int validate(vector<map_pair>* mp, int len) {
	if (isOnlylkey(len)) return 0;
	if (isSubnum(mp, len)) return 0;
	if (isLeafop(mp, len)) return 0;
	return 1;
}

int main() {
	int num = 1;
	for (int i = 0; i < 10; i++) {
		int len;
		int result;
		cin >> len;
		vector<map_pair>* mp = new vector<map_pair>(len);
		for (int j = 0; j < len; j++) {
			string src;
			char tmp;
			scanf("%d", &mp->at(j).key);
			for (int k = 0; k < 3; k++) {
				scanf("%c", &tmp);
				src.push_back(tmp);
			}
			mp->at(j).val = src.at(1);
			if (tmp != '\n') {
				scanf("%d", &mp->at(j).lkey);
				scanf("%c", &tmp);
				if (tmp != '\n')
					scanf("%d", &mp->at(j).rkey);
			}
		}
		result = validate(mp, len);

		// getchar();
		cout << "#" << num++ << " " << result << endl;
	}
}