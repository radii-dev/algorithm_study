#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int DFS(int arr1[100], int arr2[100], int target = 99) {
	stack<int> seq_stack;
	bool check[100] = { false, };
	int i = 0;
	do {
		int next_node = 0;
		seq_stack.push(i);
		check[i] = true;
		if (check[target]) return 1;
		if (check[arr1[i]] == false) next_node = arr1[i];
		else if (check[arr2[i]] == false) next_node = arr2[i];
		else {
			seq_stack.pop();
			next_node = seq_stack.top();
			seq_stack.pop();
		}
		i = next_node;
	} while (!seq_stack.empty());
	return 0;
}

int find_way(int len, vector<int>* src) {
	int arr1[100] = { 0, };
	int arr2[100] = { 0, };
	int tmp = 0;
	for (int i = 0; i < 2 * len; i += 2) {
		if (arr1[src->at(i)] == 0)
			arr1[src->at(i)] = src->at(i + 1);
		else {
			arr2[src->at(i)] = src->at(i + 1);
			if (arr1[src->at(i)] > arr2[src->at(i)]) {
				tmp = arr1[src->at(i)];
				arr1[src->at(i)] = arr2[src->at(i)];
				arr2[src->at(i)] = tmp;
			}
		}
	}
	return DFS(arr1, arr2);
}

int main() {
	int num = 1;
	for (int i = 0; i < 10; i++) {
		int len = 0;
		cin >> num;
		cin >> len;
		vector<int>* seq_pair = new vector<int>(2 * len);
		for (int j = 0; j < 2 * len; j++) {
			scanf("%d", &seq_pair->at(j));
		}

		int result = find_way(len, seq_pair);
		std::cout << "#" << num << " " << result << endl;
	}
}