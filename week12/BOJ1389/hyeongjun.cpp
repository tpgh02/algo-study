#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> g[101];
int dist[101];
int bfs(int now) {
    int ret = 0;
    queue<int> q;
    q.push(now);
    dist[now] = 0;
    while(!q.empty()) {
        now = q.front();
        ret += dist[now];
        q.pop();
        for(int next : g[now]) {
            if(dist[next] == -1) {
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
    return ret;
}
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    int ans = -1;
    int cnt = 1e9;
    for(int i = 1; i <= n; i++) {
        memset(dist, -1, sizeof(dist));
        int now = bfs(i);
        if(now < cnt) {
            cnt = now;
            ans = i;
        }
    }
    cout << ans << '\n';
    return 0;
}