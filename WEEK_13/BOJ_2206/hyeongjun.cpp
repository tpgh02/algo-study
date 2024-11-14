#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dist[1000][1000][2];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    memset(dist, -1, sizeof(dist));
    queue<tuple<int,int,int>> q;
    q.emplace(0,0,0);
    dist[0][0][0] = 1;
    while(!q.empty()) {
        auto [x, y, f] = q.front();
        q.pop();
        if(x == n - 1 && y == m - 1) {
            return !(cout << dist[x][y][f] << '\n');
        }
        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(a[nx][ny] == '1') {
                if(f == 1) continue;
                if(dist[nx][ny][1] != -1) continue;
                dist[nx][ny][1] = dist[x][y][f] + 1;
                q.emplace(nx, ny, 1);
            } else {
                if(dist[nx][ny][f] != -1) continue;
                dist[nx][ny][f] = dist[x][y][f] + 1;
                q.emplace(nx, ny, f);
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}