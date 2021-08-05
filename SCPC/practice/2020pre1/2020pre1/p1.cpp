#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;
int N, K;
vector<int> A_menu;
vector<int> B_menu;

int solve() {
	int max_kcal = 0;
	vector<int> day_kcal;
	sort(A_menu.begin(), A_menu.end());
	sort(B_menu.begin(), B_menu.end());
	for (int i = 0; i < K; i++) {
		int tmp_kcal = A_menu.at(i) + B_menu.at(K - 1 - i);
		if (tmp_kcal > max_kcal)
			max_kcal = tmp_kcal;
	}

	return max_kcal;
}

int main(int argc, char** argv)
{
	int T, test_case;

	freopen("p1sample_input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		cin >> N >> K;
		A_menu.clear();
		B_menu.clear();
		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			A_menu.push_back(tmp);
		}
		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			B_menu.push_back(tmp);
		}
		Answer = solve();


		/////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}