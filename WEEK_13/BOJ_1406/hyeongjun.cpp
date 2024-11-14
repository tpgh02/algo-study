#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    string str; cin >> str;
    deque<char> l, r;
    for(auto c : str) {
        l.push_back(c);
    }

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        char op;
        cin >> op;
        if(op == 'L') {
            if(l.empty()) continue;
            r.push_front(l.back());
            l.pop_back();
        } else if(op == 'D') {
            if(r.empty()) continue;
            l.push_back(r.front());
            r.pop_front();
        } else if(op == 'B') {
            if(l.empty()) continue;
            l.pop_back();
        } else if(op == 'P') {
            char x; cin >> x;
            l.push_back(x);
        }
    }
    for(auto c : l) {
        cout << c;
    }
    for(auto c : r) {
        cout << c;
    }
    return 0;
}