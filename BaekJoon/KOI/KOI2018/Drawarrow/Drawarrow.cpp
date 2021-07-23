#include <iostream>
#include <vector>

using namespace std;

struct dot {
	int location;
	int color;
};

int makeArrow(vector<int>* dots, int targetLocation) {
	if (dots->at(targetLocation) == -1)
		return 0;
	else {
		int len = 0;
		int tmploc[2] = { targetLocation - len, targetLocation + len };
		bool findArrow = false;
		do {
			len++;
			if (tmploc[0] >= 0)
				tmploc[0]--;
			else tmploc[0] = -1;
			if (tmploc[1] >= 0 && tmploc[1] <= dots->size())
				tmploc[1]++;
			else tmploc[1] = -1;
			if (tmploc[0] < 0) {
				if (tmploc[1] < dots->size() && dots->at(targetLocation) == dots->at(tmploc[1]))
					findArrow = true;
			}
			else if (tmploc[1] < 0) {
				if (tmploc[0] < dots->size() && dots->at(targetLocation) == dots->at(tmploc[0]))
					findArrow = true;
			}
			else {
				if ((tmploc[0] < dots->size() && dots->at(targetLocation) == dots->at(tmploc[0])) || (tmploc[1] < dots->size() && dots->at(targetLocation) == dots->at(tmploc[1])))
					findArrow = true;
			}
		} while (!findArrow);
		return len;
	}
}

int sumArrowlen(vector<int>* dots) {
	int sum = 0;
		for (int i = 0; i < dots->size(); i++) 
		sum += makeArrow(dots, i);
	return sum;
}

int main() {
	int num = 0;
	int max = 0;
	dot tmp;
	cin >> num;
	vector<dot> tmpdots;
	for (int i = 0; i < num; i++) {
		cin >> tmp.location;
		cin >> tmp.color;
		if (tmp.location > max) 
			max = tmp.location;
		tmpdots.push_back(tmp);
	}
	vector<int>* dots = new vector<int>(max + 1);
	for (vector<int>::iterator it = dots->begin(); it < dots->end(); it++)
		*it = -1;
	for (int i = 0; i < num; i++) {
		dots->at(tmpdots.at(i).location) = tmpdots.at(i).color;
	}
	
	cout << sumArrowlen(dots);
}