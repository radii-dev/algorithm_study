#include <iostream>
#define fio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
typedef long long int ll;

#include <queue>
#include <string>

int N;

void readInput() {
    cin >> N;
    cin.ignore();
    queue<int> q;
    for (int i = 0; i < N; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "push") {
            int num;
            cin >> num;
            q.push(num);
            cin.ignore();
        } else if (cmd == "pop") {
            if (q.empty()) {
                cout << "-1" << "\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if (cmd == "size") {
            cout << q.size() << "\n";
        } else if (cmd == "empty") {
            if (q.empty()) cout << "1" << "\n";
            else cout << "0" << "\n";
        } else if (cmd == "front") {
            if (q.empty()) {
                cout << "-1" << "\n";
            } else {
                cout << q.front() << "\n";
            }
        } else if (cmd == "back") {
            if (q.empty()) {
                cout << "-1" << "\n";
            } else {
                cout << q.back() << "\n";
            }
        }
    }
}

void solve() {
    readInput();

}

int main (int argc, char* argv[]) {
    fio;
    freopen("./bin/input1.txt", "r", stdin);

    solve();

    return 0;
}

