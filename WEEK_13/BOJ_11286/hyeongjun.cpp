#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int n; cin >> n;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x == 0) {
            if(pq.empty()) {
                cout << 0 << '\n';
                continue;
            }
            auto [num, f] = pq.top();
            pq.pop();
            if(f == -1) num *= -1;
            cout << num << '\n';
        } else {
            if(x < 0) {
                pq.emplace(-x, -1);
            } else {
                pq.emplace(x, 1);
            }
        }
    }
    return 0;
}