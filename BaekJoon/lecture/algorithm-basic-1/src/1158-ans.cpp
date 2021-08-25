#include <iostream>
#define fio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
typedef long long int ll;

int N, K;
int d[5001];

void readInput() {
    cin >> N >> K;
}

void solve() {
    readInput();
    for (int i = 1; i <= N; ++i) d[i] = i;
    cout << "<";
    int idx = 0;
    while (N > 0) {
        idx = (idx + K) % N;
        if (idx == 0) idx = N;
        if (N == 1) cout << d[1] << ">" << "\n";
        else {
            cout << d[idx] << ", ";
            for (int i = idx; i < N; i++) d[i] = d[i + 1];
            idx--;
        }
        N--;
    }
}

int main (int argc, char* argv[]) {
    fio;
    freopen("./bin/input1.txt", "r", stdin);

    solve();

    return 0;
}

