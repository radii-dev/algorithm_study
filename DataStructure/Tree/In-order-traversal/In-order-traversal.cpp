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

string In_order_traversal(vector<map_pair>* mp, vector<bool>* keys) {
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
			if (keys->at(i - 1) == false) {
				result.push_back(mp->at(i - 1).val);
				keys->at(i - 1) = true;
				if ((mp->at(i - 1).rkey > 0) && (keys->at(mp->at(i - 1).rkey - 1) == false)) {
					if (st.empty()) st.push(mp->at(i - 1).key);
					i = mp->at(i - 1).rkey;
					process = 1;
				}
				else process = 3;
			}
			break;
		case 3:
			i = st.top();
			st.pop();
			process = 2;
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

int main() {
	int num = 1;
	for (int i = 0; i < 10; i++) {
		int len;
		//char a[1] = { 0 };
		string result;
		cin >> len;
		vector<map_pair>* mp = new vector<map_pair>(len);
		vector<bool>* keys = new vector<bool>(len);
		for (int j = 0; j < len; j++) keys->at(j) = false;
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
		result = In_order_traversal(mp, keys);

		// getchar();
		cout << "#" << num++ << " " << result << endl;
	}
}