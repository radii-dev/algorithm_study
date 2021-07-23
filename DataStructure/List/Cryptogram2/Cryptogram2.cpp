#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <vector>
using namespace std;

class cryptogram {
private:
	int srccryptlen = 0;
	list<int> srccrypt;

public:
	cryptogram() {}
	cryptogram(int len) {
		srccryptlen = len;
	}
	cryptogram(cryptogram& c) {
		srccryptlen = c.srccryptlen;
		srccrypt.assign(c.srccrypt.begin(), c.srccrypt.end());
	}
	void setSrccrytlen() {
		cin >> srccryptlen;
	}
	void setSrccrytlen(int len) {
		srccryptlen = len;
	}
	void setSrccrypt() {
		for (int i = 0; i < srccryptlen; i++) {
			int temp;
			scanf("%d", &temp);
			srccrypt.push_back(temp);
		}
	}
	void setSrccrypt(list<int> src) {
		srccrypt = src;
	}
	int getSrccrytlen() {
		return srccryptlen;
	}
	list<int> getSrccrypt() {
		return srccrypt;
	}
	void printTenvalues() {
		list<int>::iterator it = srccrypt.begin();
		for (int j = 0; j < 10; j++, it++) 
			cout << " " << *it;
	}
};

class command {
private:
	int cmdlen = 0;
	struct cmdvar {
		char cmd = '\0';
		int x = -1;
		int y = -1;
		list<int> s;
	};
	vector<cmdvar> cmdv;
	
public:
	void setCmdlen() {
		cin >> cmdlen;
	}
	void parsingCMD() {
		//vector<cmdvar>* cmdv = new vector<cmdvar>(cmdlen);
		char dummy;
		for (int i = 0; i < cmdlen; i++) {
			cmdvar tmp;
			scanf("%c", &dummy);
			scanf("%c", &tmp.cmd);
			switch (tmp.cmd) {
				case 'I':
					scanf("%d", &tmp.x);
					scanf("%d", &tmp.y);
					for (int j = 0; j < tmp.y; j++) {
						int temp;
						scanf("%d", &temp);
						tmp.s.push_back(temp);
					}
					break;

				case 'D':
					scanf("%d", &tmp.x);
					scanf("%d", &tmp.y);
					break;

			}
			cmdv.push_back(tmp);
		}
	}
	void insertCMD(list<int>& target, int cnt) {
		//list<int> result = target;
		list<int>::iterator it = target.begin();	// tmp가 클래스의 멤버리스트가 아니라서 되는거같음.
		for (int i = 0; i < cmdv.at(cnt).x; i++) it++;
		for (int i = 0; i < cmdv.at(cnt).y; i++) {
			target.insert(it, cmdv.at(cnt).s.front());
			if (!cmdv.at(cnt).s.empty()) 
				cmdv.at(cnt).s.pop_front();
		}
		//return result;
	}
	void deleteCMD(list<int>& target, int cnt) {
		//list<int>::iterator it = target.begin();
		//for (int i = 0; i < cmdv.at(cnt).x; i++) it++;
		for (int i = 0; i < cmdv.at(cnt).y; i++) {
			list<int>::iterator it = target.begin();
			for (int j = 0; j < cmdv.at(cnt).x; j++) it++;
			target.erase(it);
		}
	}
	void processingCMD(cryptogram& cry, cryptogram& result) {
		//cryptogram result(cry.getSrccrytlen());
		list<int> tmp = cry.getSrccrypt();
		for (int i = 0; i < cmdlen; i++) {
			switch (cmdv.at(i).cmd) {
				case 'I':
					insertCMD(tmp, i);
					break;

				case 'D':
					deleteCMD(tmp, i);
					break;

			}
		}
		result.setSrccrypt(tmp);
		result.setSrccrytlen(tmp.size());
		//return result;
	}
};

int main() {
	int num = 1;
	for (int i = 0; i < 10; i++) {
		cryptogram crypt;
		cryptogram result;
		command c;
		int srccryptlen = 0;
		int srccrypt[20] = { 0, };
		int cmdlen = 0;
		crypt.setSrccrytlen();
		crypt.setSrccrypt();
		c.setCmdlen();
		c.parsingCMD();
		c.processingCMD(crypt, result);
		//list<int>::iterator it = result.getSrccrypt().begin();
		//list<int>::iterator it = c.processingCMD(crypt, result).getSrccrypt().begin();

		//getchar();
		//cout << result.getSrccrypt().front() << endl;
		//cout << *result.getSrccrypt().begin() << endl;
		cout << "#" << num++;
		result.printTenvalues();
		cout << endl;
		//cout << "#" << num++ << " " << result << endl;
	}
}