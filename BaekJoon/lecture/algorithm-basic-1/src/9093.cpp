#include <iostream>
#define fio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
typedef long long int ll;

#include <stack>
#include <string>

int N;
string str[1000000];

void readInput() {
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) getline(cin, str[i]);
}

void solve() {
    readInput();
    stack<char> sta;
    for (int i = 0; i < N; i++) {
        for (string::iterator iter = str[i].begin(); iter != str[i].end(); ++iter) {
            if (*iter ==  ' ') {
                while (!sta.empty()) {
                    cout << sta.top();
                    sta.pop();
                }
                cout << " ";
            } else {
                sta.push(*iter);
            }
        }
        while (!sta.empty()) {
            cout << sta.top();
            sta.pop();
        }
        cout << "\n";
    }
}

int main (int argc, char* argv[]) {
    fio;
    freopen("9093_tc1.txt", "r", stdin);

    solve();

    return 0;
}

