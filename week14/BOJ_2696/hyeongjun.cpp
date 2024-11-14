#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    cout << (n + 1) / 2 << '\n';
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        l.push(x);
        while(l.size() > r.size() + 1) {
            r.push(l.top());
            l.pop();
        }
        while(!l.empty() && !r.empty() && l.top() > r.top()) {
            r.push(l.top()); l.pop();
            l.push(r.top()); r.pop();
        }
        if(i % 2 == 0) {
            cout << l.top() << ' ';
        }
    }
    cout << '\n';
    return;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}