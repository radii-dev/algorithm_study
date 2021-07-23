#include <iostream>

using namespace std;

bool isPalindrome(string src) {
	for (int i = 0; i < src.size() / 2; i++) 
		if (src.at(i) != src.at(src.size() - 1 - i))
			return false;
	return true;
}

void isPalindrome(string src, int* result) {
	for (int i = 0; i < src.size() / 2; i++) {
		if (src.at(i) != src.at(src.size() - 1 - i)) {
			result[0] = 0;
			result[1] = i;
			return;
		}
	}
	result[0] = 1;
	result[1] = 0;
}

int isPseudo_Palindrome() {
	int arr[2];
	string src;
	cin >> src;
	isPalindrome(src, arr);
	if (arr[0]) return 0;
	else {
		string tmp = src;
		string::iterator it = tmp.begin() + arr[1];
		tmp.erase(it);
		if (isPalindrome(tmp)) return 1;

		tmp = src;
		it = tmp.end() - arr[1] - 1;
		tmp.erase(it);
		if (isPalindrome(tmp)) return 1;
	}
	return 2;
}

int main() {
	int len;
	cin >> len;

	for (int i = 0; i < len; i++)
		cout << isPseudo_Palindrome() << endl;
}