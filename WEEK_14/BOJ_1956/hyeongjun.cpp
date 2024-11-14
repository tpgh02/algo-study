#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int dist[401][401];
int main() {
    fastio;
    cin >> n >> m;
    memset(dist, -1, sizeof(dist));
    for(int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        dist[t1][t2] = t3;
    }

    for(int x = 1; x <= n; x++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(dist[i][x] == -1 || dist[x][j] == -1) continue;
                if(dist[i][j] == -1 || dist[i][j] > dist[i][x] + dist[x][j]) {
                    dist[i][j] = dist[i][x] + dist[x][j];
                }
            }
        }
    }
    int ans = 1e9;
    for(int i = 1; i <= n; i++) {
        if(dist[i][i] != -1) {
            ans = min(ans, dist[i][i]);
        }
    }

    if(ans == 1e9) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}