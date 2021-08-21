#include <iostream>
#define fio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
typedef long long int ll;

#include <stack>
#include <string>

int N, M;
string str;
stack<char> cursor_left, cursor_right;

void readInput() {
    getline(cin, str);
    for (string::iterator iter = str.begin(); iter != str.end(); ++iter) 
        cursor_left.push(*iter);
    cin >> M;
    for (int i = 0; i < M; ++i) {
        char cmd;
        cin >> cmd;
        if (cmd == 'L' && !cursor_left.empty()) {
            cursor_right.push(cursor_left.top());
            cursor_left.pop();
        } else if (cmd == 'D' && !cursor_right.empty()) {
            cursor_left.push(cursor_right.top());
            cursor_right.pop();
        } else if (cmd == 'B' && !cursor_left.empty()) {
            cursor_left.pop();
        } else if (cmd == 'P') {
            cin >> cmd;
            cursor_left.push(cmd);
        }
    }
}

void solve() {
    readInput();
    while (!cursor_left.empty()) {
        cursor_right.push(cursor_left.top());
        cursor_left.pop();
    }
    while (!cursor_right.empty()) {
        cout << cursor_right.top();
        cursor_right.pop();
    }
    cout << "\n";
}

int main (int argc, char* argv[]) {
    fio;
    freopen("./bin/input3.txt", "r", stdin);

    solve();

    return 0;
}

