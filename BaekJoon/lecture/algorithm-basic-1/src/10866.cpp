#include <iostream>
#define fio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
typedef long long int ll;

#include <deque>
#include <string>

int N;

void readInput() {
    cin >> N;
    cin.ignore();
    deque<int> deq;
    for (int i = 0; i < N; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "push_front") {
            int num;
            cin >> num;
            deq.push_front(num);
            cin.ignore();
        } else if (cmd == "push_back") {
            int num;
            cin >> num;
            deq.push_back(num);
            cin.ignore();
        } else if (cmd == "pop_front") {
            if (deq.empty()) {
                cout << "-1" << "\n";
            } else {
                cout << deq.front() << "\n";
                deq.pop_front();
            }
        } else if (cmd == "pop_back") {
            if (deq.empty()) {
                cout << "-1" << "\n";
            } else {
                cout << deq.back() << "\n";
                deq.pop_back();
            }
        } else if (cmd == "size") {
            cout << deq.size() << "\n";
        } else if (cmd == "empty") {
            if (deq.empty()) cout << "1" << "\n";
            else cout << "0" << "\n";
        } else if (cmd == "front") {
            if (deq.empty()) {
                cout << "-1" << "\n";
            } else {
                cout << deq.front() << "\n";
            }
        } else if (cmd == "back") {
            if (deq.empty()) {
                cout << "-1" << "\n";
            } else {
                cout << deq.back() << "\n";
            }
        }
    }
}

void solve() {
    readInput();

}

int main (int argc, char* argv[]) {
    fio;
    freopen("./bin/input2.txt", "r", stdin);

    solve();

    return 0;
}

