#include <iostream>
#include <string>
using namespace std;

int strmatching(string src, char cmp[10]) {
	int cmplen = 0;
	int srcptr = 0;
	int count = 0;
	int result = 0;
	for (int i = 0; i < 10; i++)
		if (cmp[i] != 0) cmplen++;
	srcptr = cmplen - 1;
	while (srcptr < src.length()) {
		int skip = 0;
		bool matched = false;
		for (int i = cmplen - 1; i >= 0; i--) {
			if (src.at(srcptr) == cmp[i]) {
				skip = cmplen - 1 - i;
				matched = true;
				break;
			}
		}
		if (matched == false) {
			skip = cmplen;
			if (count > 0) {
				srcptr += (count + 1);
				count = 0;
			}
			else srcptr += skip;
		}
		else if ((matched == true) && (skip == count)) {
			srcptr--;
			count++;
		}
		else {
			if (count > 0) {
				srcptr += (count + 1);
				count = 0;
			}
			else srcptr += skip;
		}
		if (count == cmplen) result++;
		
		/*
		if ((count > 0) && ((matched == false) || ((matched == true) && (skip != count)))) {
			srcptr += (count + 1);
			count = 0;
		}
		else srcptr += skip;
		*/
	}
	return result;
}

int main() {
	int num = 0;
	for (int i = 0; i < 10; i++) {
		string srcstr;
		char cmpstr[10] = { 0, };
		cin >> num;
		cin >> cmpstr;
		cin >> srcstr;
		int result = 0;
		result = strmatching(srcstr, cmpstr);

		std::cout << "#" << num << " " << result << endl;
	}
}