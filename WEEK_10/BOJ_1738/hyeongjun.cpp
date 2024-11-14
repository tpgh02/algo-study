#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
vector<pair<int, ll>> g[101];
ll dist[101];
bool visited[101];
int p[101];
bool check(int now) { 
    if(now == -1) return false;
    visited[now] = true;
    if(p[now] != -1 && visited[p[now]]) return true;
    return check(p[now]);
}
void trace(int now) {
    if(now == -1) return ;
    trace(p[now]);
    cout << now << ' ';
}
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        ll t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back({t2, t3});
    }

    for(int i = 1; i <= n; i++) {
        dist[i] = -1e14;
        p[i] = -1;
    }
    dist[1] = 0;
    for(int t = 0; t < n + 1; t++) {
        for(int now = 1; now <= n; now++) {
            if(dist[now] == -1e14) continue;
            for(auto &[next, cost] : g[now]) {
                if(dist[next] < dist[now] + cost) {
                    if(t == n - 1) {
                        dist[now] = 1e14;
                        dist[next] = 1e14;
                        p[next] = now;
                    } else {
                        dist[next] = dist[now] + cost;
                        p[next] = now;
                    }
                }
            }
        }
    }
    if(check(n) || dist[n] == -1e14) cout << -1 << '\n';
    else {
        trace(n);
    }


    return 0;
}