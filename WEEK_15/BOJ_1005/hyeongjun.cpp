#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, e;
vector<int> g[1001];
int a[1001], ans[1001], ind[1001];
void init() {
    for(int i = 1; i <= n; i++) {
        g[i].clear();
        ans[i] = ind[i] = 0;
    }
}
void solve() {
    cin >> n >> m;
    init();
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        ind[t2] += 1;
    }
    cin >> e;

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(ind[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int now = q.front();
        ans[now] += a[now];
        q.pop();
        for(int next : g[now]) {
            ans[next] = max(ans[next], ans[now]);
            ind[next] -= 1;
            if(ind[next] == 0) {
                q.push(next);
            }
        }
    }
    cout << ans[e] << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}