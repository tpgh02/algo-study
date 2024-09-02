#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j]) {
                ans += 1;
                queue<pii> q;
                q.emplace(i, j);
                a[i][j] = 0;
                while(!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for(int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(a[nx][ny]) {
                            q.emplace(nx, ny);
                            a[nx][ny] = 0;
                        }
                    }

                }
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}