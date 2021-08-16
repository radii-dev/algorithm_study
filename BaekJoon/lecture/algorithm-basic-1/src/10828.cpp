#include <iostream>
#define fio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
typedef long long int ll;

#include <stack>
#include <string>

int N;

void readInput() {
    cin >> N;
}

void solve() {
    readInput();
    string cmd;
    stack<int> ans;
    for (int i = 0; i < N; i++) {
        cin >> cmd;
        if (cmd == "push") {
            int num;
            cin >> num;
            ans.push(num);
        }
        else if (cmd == "pop") {
            if (ans.empty()) cout << -1 << "\n";
            else {
                cout << ans.top() << "\n";
                ans.pop();
            }
        }
        else if (cmd == "size") 
            cout << ans.size() << "\n";
        else if (cmd == "empty") {
            if (ans.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        } 
        else if (cmd == "top") {
            if (ans.empty()) cout << -1 << "\n";
            else cout << ans.top() << "\n";
        } 
    }
}

int main (int argc, char* argv[]) {
    fio;
    freopen("10828_tc2.txt", "r", stdin);

    solve();
    
    return 0;
}

