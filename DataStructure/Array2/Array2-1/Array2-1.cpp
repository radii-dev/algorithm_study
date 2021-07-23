#include <iostream>
using namespace std;

int maxsumcol(int a[100][100]) {
	int sum[100] = { 0, };
	int result = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			sum[i] += a[i][j];
		}
	}
	for (int i = 0; i < 100; i++) {
		if (sum[i] > result) result = sum[i];
	}
	return result;
}

int maxsumrow(int a[100][100]) {
	int sum[100] = { 0, };
	int result = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			sum[i] += a[j][i];
		}
	}
	for (int i = 0; i < 100; i++) {
		if (sum[i] > result) result = sum[i];
	}
	return result;
}

int maxsumcross(int a[100][100]) {
	int sum[2] = { 0, };
	int result = 0;
	for (int i = 0; i < 100; i++) {
		sum[0] += a[i][i];
		sum[1] += a[i][100 - i];
	}
	result = (sum[0] > sum[1]) ? sum[0] : sum[1];
	return result;
}

int main() {
	for (int i = 0; i < 10; i++) {
		int num = 0;
		int max = 0;
		int a[100][100] = { 0 };
		cin >> num;
		for (int j = 0; j < 100; j++) {
			for (int k = 0; k < 100; k++) {
				cin >> a[j][k];
			}
		}
		if (maxsumcol(a) > max) max = maxsumcol(a);
		if (maxsumrow(a) > max) max = maxsumrow(a);
		if (maxsumcross(a) > max) max = maxsumcross(a);
		cout << "#" << i + 1 << " " << max << endl;
	}
}