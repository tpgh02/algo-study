#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> g[1001], pre, in;
void go(int l1, int r1, int l2, int r2) {
    if(r1 - l1 == 1) return ;
    int mid = find(in.begin(), in.end(), pre[l1]) - in.begin();
    int lsize = mid - l2;
    int rsize = r2 - mid - 1;

    if(lsize > 0) {
        g[pre[l1]].push_back(pre[l1 + 1]);
        go(l1 + 1, l1 + 1 + lsize, l2, mid);
    }

    if(rsize > 0) {
        g[pre[l1]].push_back(pre[l1 + lsize + 1]);
        go(l1 + 1 + lsize, r1, mid + 1, r2);
    }

}
void post(int now) {
    for(int next: g[now]) {
        post(next);
    }
    cout << now << ' ';
}
void solve() {
    for(int i = 0; i <= 1000; i++) g[i].clear();
    pre.clear();
    in.clear();

    int n; cin >> n;
    pre.resize(n);
    in.resize(n);

    for(int &x : pre) cin >> x;
    for(int &x : in) cin >> x;

    go(0, n, 0, n);

    post(pre[0]);
    cout << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}