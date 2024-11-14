#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int dist[1001], p[1001];
vector<pii> g[1001];
int main() {
    fastio;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        dist[i] = 1e9;
    }

    for(int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].emplace_back(t2, t3);
        g[t2].emplace_back(t1, t3);
    }
    dist[1] = 0;
    
    priority_queue<pii> pq;
    pq.emplace(0, 1);
    
    while(!pq.empty()) {
        auto [d, now] = pq.top();
        pq.pop();

        d *= -1;
        if(dist[now] < d) continue;
        
        for(auto [next, cost] : g[now]) {
            if(dist[next] > d + cost) {
                dist[next] = d + cost;
                p[next] = now;
                pq.emplace(-dist[next], next);
            }
        }
    }

    vector<int> ans;
    for(int i = 2; i <= n; i++) {
        if(dist[i] == 1e9) continue;
        ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for(auto x : ans) {
        cout << x << ' ' << p[x] << '\n';
    }

    return 0;
}