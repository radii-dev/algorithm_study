#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<int> cycle(queue<int> qu) {
	for (int i = 1; i <= 5; i++) {
		int tmp = qu.front() - i;
		if (tmp < 0) tmp = 0;
		qu.push(tmp);
		qu.pop();
		if (qu.back() == 0) break;
	}
	return qu;
}

queue<int> mk_Passwd(int src[8], queue<int> qu) {
	for (int i = 0; i < 8; i++) qu.push(src[i]);
	while (qu.back() != 0) qu = cycle(qu);
	return qu;
}

int main() {
	int num = 1;
	for (int i = 0; i < 10; i++) {
		int src[8] = { 0, };
		queue<int> result;
		cin >> num;
		for (int j = 0; j < 8; j++) {
			scanf("%d", &src[j]);
		}

		result = mk_Passwd(src, result);
		cout << "#" << num << " ";
		for (int j = 0; j < 8; j++) {
			cout << result.front() << " ";
			result.pop();
		}
		cout << endl;
	}
}