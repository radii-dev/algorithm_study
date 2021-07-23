#include <iostream>
#define length 100
using namespace std;

class Block {
public:
	int block[length] = { 0, };
	int max = 0;
	int maxindex = 0;
	int min = 100;
	int minindex = 0;
};

Block dump(Block B) {
	Block C;
	if (B.max == B.min) return B;
	else {
		B.block[B.maxindex]--;
		B.block[B.minindex]++;
		for (int j = 0; j < length; j++) C.block[j] = B.block[j];
		for (int j = 0; j < length; j++) {
			if (C.block[j] > C.max) {
				C.max = C.block[j];
				C.maxindex = j;
			}
			if (C.block[j] < C.min) {
				C.min = C.block[j];
				C.minindex = j;
			}
		}
	}
	return C;
}

int main() {
	Block B;
	for (int i = 0; i < 10; i++) {
		int dcount = 0;
		cin >> dcount;
		for (int j = 0; j < length; j++) {
			cin >> B.block[j];
			if (B.block[j] > B.max) {
				B.max = B.block[j];
				B.maxindex = j;
			}
			if (B.block[j] < B.min) {
				B.min = B.block[j];
				B.minindex = j;
			}
		}
		for (int j = 0; j < dcount; j++) {
			B = dump(B);
		}
		cout << "#" << i + 1 << " " << B.max - B.min << endl;
	}
}