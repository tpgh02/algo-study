#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    string p; cin >> p;
    int n; cin >> n;
    string str; cin >> str;
    stringstream ss(str);

    deque<int> dq;
    char tmpc;
    int tmp;

    ss >> tmpc;
    for(int i = 0; i < n; i++) {
        ss >> tmp >> tmpc;
        dq.push_back(tmp);
    }

    bool f = true;
    for(auto &c : p) {
        if(c == 'R') {
            f ^= true;
        } else {
            if(dq.empty()) {
                cout << "error" << '\n';
                return;
            }
            if(f) {
                dq.pop_front();
            } else {
                dq.pop_back();
            }
        }
    }

    cout << '[';
    if(f) {
        for(int i = 0; i < (int)dq.size() - 1; i++) {
            cout << dq[i] << ',';
        }
        if(!dq.empty()) cout << dq.back();
    } else {
        for(int i = (int)dq.size() - 1; i>= 1; i--) {
            cout << dq[i] << ',';
        }
        if(!dq.empty()) cout << dq.front();
    }
    cout << ']' << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}