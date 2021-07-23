#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int get_weight(char token) {
	switch (token) {
		case '+':
			return 1;
			break;
		case '-':
			return 1;
			break;
		case '*':
			return 2;
			break;
		case '/':
			return 2;
			break;
		case '(':
			return 3;
			break;
	}
}

bool isNumber(char token) {
	if (token >= 48 && token <= 57) { // ascii 0~9
		return true;
	}
	else return false;
}

vector<char>* mk_post_not(int len, vector<char>* src, vector<char>* dst) {
	stack<char> op;
	int i = 0;
	int j = 0;
	do {
		if (isNumber(src->at(i))) dst->at(j++) = src->at(i);
		else {
			if (op.empty()) op.push(src->at(i));
			else {
				while (get_weight(op.top()) >= get_weight(src->at(i))) {
					dst->at(j++) = op.top();
					op.pop();
					if (op.empty()) break;
				}
				op.push(src->at(i));
			}
		}
	} while (++i < src->size());
	while (!op.empty()) {
		dst->at(j++) = op.top();
		op.pop();
	}
	return dst;
}

int sum(int len, vector<char>* src) {
	vector<char>* post_not = new vector<char>(len);
	stack<int> num;
	int i = 0;
	int result = 0;
	mk_post_not(len, src, post_not);
	do {
		if (isNumber(post_not->at(i))) num.push(post_not->at(i) - '0');
		else {
			int a = 0, b = 0;
			switch (post_not->at(i)) {
				case '+':
					a = num.top();
					num.pop();
					b = num.top();
					num.pop();
					num.push(a + b);
					break;
				case '-':
					a = num.top();
					num.pop();
					b = num.top();
					num.pop();
					num.push(b - a);
					break;
				case '*':
					a = num.top();
					num.pop();
					b = num.top();
					num.pop();
					num.push(a * b);
					break;
				case '/':
					a = num.top();
					num.pop();
					b = num.top();
					num.pop();
					num.push(b / a);
					break;
			}
		}
	} while (++i < post_not->size());
	result = num.top();
	return result;
}

int main() {
	int num = 1;
	for (int i = 0; i < 10; i++) {
		int len = 0;
		char dummy;
		cin >> len;
		vector<char>* equation = new vector<char>(len);
		scanf("%c", &dummy);
		for (int j = 0; j <len; j++) {
			scanf("%c", &equation->at(j));
		}

		int result = sum(len, equation);
		std::cout << "#" << num++ << " " << result << endl;
	}
}