#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <cstring>
using namespace std;

struct map_pair {
	int key;
	string val;
	int lkey = 0;
	int rkey = 0;
};

string Post_order_traversal(vector<map_pair>* mp, vector<bool>* keys) {
	int i = 1;
	int cnt = 0;
	int process = 1;
	stack<int> st;
	string result;
	do {
		cnt = 0;
		switch (process) {
		case 1:
			if ((mp->at(i - 1).lkey > 0) && (keys->at(mp->at(i - 1).lkey - 1) == false)) {
				st.push(mp->at(i - 1).key);
				i = mp->at(i - 1).lkey;
				continue;
			}
			else process = 2;
			break;
		case 2:
			for (int j = 0; j < mp->at(i - 1).val.size(); j++)
				result.push_back(mp->at(i - 1).val.at(j));
			result.push_back(' ');
			keys->at(i - 1) = true;
			if (!st.empty()) {
				i = st.top();
				st.pop();
			}
			process = 3;
			break;
		case 3:
			if ((mp->at(i - 1).rkey > 0) && (keys->at(mp->at(i - 1).rkey - 1) == false)) {
				st.push(mp->at(i - 1).key);
				i = mp->at(i - 1).rkey;
				process = 1;
			}
			else process = 2;
			break;
		default:
			process = 1;
		}
		for (int k = 0; k < keys->size(); k++, cnt++) {
			if (!keys->at(k)) break;
		}
	} while (cnt < keys->size());
	return result;
}

bool isNumber(char token) {
	if (token >= 48 && token <= 57) { // ascii 0~9
		return true;
	}
	else return false;
}

float cal(vector<map_pair>* mp, vector<bool>* keys) {
	string equation = Post_order_traversal(mp, keys);
	stack<float> num;
	int i = 0;
	int result = 0;
	do {
		if (equation.at(i) != ' ') {
			if (isNumber(equation.at(i))) {
				string number;
				do {
					number.push_back(equation.at(i));
				} while (isNumber(equation.at(++i)));
				num.push(atoi(number.c_str()));
			}
			else {
				int a = 0, b = 0;
				switch (equation.at(i)) {
				case '+':
					a = num.top();
					num.pop();
					b = num.top();
					num.pop();
					num.push(a + b);
					break;
				case '*':
					a = num.top();
					num.pop();
					b = num.top();
					num.pop();
					num.push(a * b);
					break;
				case '-':
					a = num.top();
					num.pop();
					b = num.top();
					num.pop();
					num.push(b - a);
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
		}
	} while (++i < equation.size());
	result = num.top();
	return result;
}

int main() {
	int num = 1;
	for (int i = 0; i < 10; i++) {
		int len;
		int result;
		cin >> len;
		vector<map_pair>* mp = new vector<map_pair>(len);
		vector<bool>* keys = new vector<bool>(len);
		for (int j = 0; j < len; j++) keys->at(j) = false;
		for (int j = 0; j < len; j++) {
			string src;
			char tmp;
			scanf("%d", &mp->at(j).key);
			scanf("%c", &tmp);
			do {
				scanf("%c", &tmp);
				src.push_back(tmp);
			} while (tmp >= '0' && tmp <= '9');
			if (src.at(src.size() - 1) == ' ') src.pop_back();
			if (src.at(src.size() - 1) == '\n') src.pop_back();
			for (int k = 0; k < src.size(); k++) 
				mp->at(j).val.push_back(src.at(k));
			if (tmp != '\n') {
				scanf("%d", &mp->at(j).lkey);
				scanf("%c", &tmp);
				if (tmp != '\n')
					scanf("%d", &mp->at(j).rkey);
			}
		}
		result = cal(mp, keys);

		// getchar();
		cout << "#" << num++ << " " << result << endl;
	}
}