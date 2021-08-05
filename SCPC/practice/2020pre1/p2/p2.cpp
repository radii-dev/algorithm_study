#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;
int n, k;
int X[3001], Y[3001];
int psX[3001], psY[3001];			//prefix sum of X and Y
int ptnextX[3001], ptnextY[3001];
int psdpX[3001][3001], psdpY[3001][3001];		//prefix sum of dp[X] and dp[Y]
int dp[3001][3001];

void readInput() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> X[i];
	for (int i = 1; i <= n; i++) cin >> Y[i];
}

void solve() {
	readInput();
	for (int i = 1; i <= n; i++) psX[i] = psX[i - 1] + X[i];
	for (int i = 1; i <= n; i++) psY[i] = psY[i - 1] + Y[i];
	for (int i = 0; i <= n; i++) {
		ptnextX[i] = lower_bound(psX, psX + i + 1, psX[i] - k) - psX;
		ptnextY[i] = lower_bound(psY, psY + i + 1, psY[i] - k) - psY;
	}

	int ans1 = 0; int ans2 = 0;
	dp[0][0] = psdpX[0][0] = psdpY[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 && j == 0) continue;
			bool isFin = false;
			if (i > 0) {
				int sumX = psdpX[i - 1][j];
				if (ptnextX[i] > 0) sumX -= psdpX[ptnextX[i] - 1][j];
				int caseX = i - ptnextX[i];
				if (sumX < caseX) isFin = true;
			}
			if (j > 0) {
				int sumY = psdpY[i][j - 1];
				if (ptnextY[j] > 0) sumY -= psdpY[i][ptnextY[j] - 1];
				int caseY = j - ptnextY[j];
				if (sumY < caseY) isFin = true;
			}
			if (isFin) dp[i][j] = 1;
			else dp[i][j] = 0;
			psdpX[i][j] = (i > 0 ? psdpX[i - 1][j] : 0) + dp[i][j];
			psdpY[i][j] = (j > 0 ? psdpY[i][j - 1] : 0) + dp[i][j];
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (dp[i][j]) ans1++;
			else ans2++;
		}
	}
	cout << ans1 << " " << ans2;
}

int main(int argc, char** argv)
{
	int T, test_case;
	freopen("p2sample_input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cout << "Case #" << test_case + 1 << endl;
		solve();  cout << endl;
	}

	return 0;
}