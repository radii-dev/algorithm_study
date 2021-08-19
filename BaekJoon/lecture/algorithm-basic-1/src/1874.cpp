#include <iostream>
#define fio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
typedef long long int ll;

#include <stack>
#include <vector>

int n;
int arr[100001];

void readInput() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
}

void solve() {
    readInput();
    int idx = 0;
    int cnt = 1;
    int failflag = 0;
    vector<char> ans;
    stack<int> sta;
    while (idx < n) {
        if (sta.empty() || sta.top() < arr[idx]) {
            sta.push(cnt++);
            ans.push_back('+');
        } else if (sta.top() == arr[idx]) {
            sta.pop();
            ans.push_back('-');
            idx++;
        } else {
            failflag = 1;
            break;
        }
    }
    if (failflag == 1) cout << "NO" << "\n";
    else
        for (vector<char>::iterator iter = ans.begin(); iter != ans.end(); ++iter) 
            cout << *iter << "\n";
}

int main (int argc, char* argv[]) {
    fio;
    freopen("./bin/input2.txt", "r", stdin);

    solve();

    return 0;
}

