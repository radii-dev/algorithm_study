#include <iostream>
#define fio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
typedef long long int ll;

#include <stack>
#include <string>

int N;

void readInput() {
    cin >> N;
    cin.ignore();
}

void solve() {
    readInput();
    for (int i = 0; i < N; ++i) {
        int cnt = 0;
        string str;
        getline(cin, str);
        for (string::iterator iter = str.begin(); iter != str.end(); ++iter) {
            if (*iter == '(') cnt++;
            else if (cnt > 0) cnt--;
            else {
                cnt = 1000000;
                break;
            }
        }
        if (cnt == 0) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}

int main (int argc, char* argv[]) {
    fio;
    freopen("9012_tc2.txt", "r", stdin);

    solve();

    return 0;
}

