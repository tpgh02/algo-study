#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
vector<pii> g[101];
int ind[101], outd[101], a[101];
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].emplace_back(t2, t3);
        ind[t2] += 1;
        outd[t1] += 1;
    }

    queue<int> q;
    q.push(n);
    a[n] = 1;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(auto [next, cost] : g[now]) {
            ind[next]--;
            a[next] += a[now] * cost;
            if(ind[next] == 0) {
                q.push(next);
            }
        }
    }

    for(int i = 1; i < n; i++) {
        if(outd[i] == 0 && a[i] != 0)  {
            cout << i << ' ' << a[i] << '\n';
        }
    }

    return 0;
}