#include <iostream>
#define fio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
typedef long long int ll;

#include <vector>

int N, K;

void readInput() {
    cin >> N >> K;
}

void solve() {
    readInput();
    vector<bool> arr(N, false);
    int cnt = 1;
    int idx = 0;
    int rot = 0;
    cout << "<";
    while (cnt <= N) {
        if (arr[idx] == false) {
            if (rot == K - 1) {
                arr[idx] = true;
                cout << idx + 1;
                rot = 0;
                cnt++;
                if (cnt <= N) cout << ", ";
            } else rot++;
        }
        idx = (idx + 1) % N;
    }
    cout << ">" << "\n";
}

int main (int argc, char* argv[]) {
    fio;
    freopen("./bin/input1.txt", "r", stdin);

    solve();

    return 0;
}

