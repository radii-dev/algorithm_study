#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int parenthese_validity(stack<char> stack, vector<char>* src, int len) {
	for (int i = 0; i < len; i++) {	
		if (src->at(i) == '[' || src->at(i) == '{' || src->at(i) == '(' || src->at(i) == '<') {
			stack.push(src->at(i));
		}
		else {
			if (src->at(i) == ']' && stack.top() == '[') {
				stack.pop();
			}
			else if (src->at(i) == '}' && stack.top() == '{') {
				stack.pop();
			}
			else if (src->at(i) == ')' && stack.top() == '(') {
				stack.pop();
			}
			else if (src->at(i) == '>' && stack.top() == '<') {
				stack.pop();
			}
			else return 0;
		}
	}
	if (!stack.empty()) return 0;
	return 1;
}

int main() {
	int num = 1;
	for (int i = 0; i < 10; i++) {
		int len = 0;
		char dummy;
		stack<char> stack;
		cin >> len;
		vector<char>* src = new vector<char>(len);
		scanf("%c", &dummy);
		for (int j = 0; j < len; j++) {
			scanf("%c", &src->at(j));
		}

		int result = parenthese_validity(stack, src, len);
		std::cout << "#" << num++ << " " << result << endl;
	}
}