#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dist[50][50][1 << 6];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<string> a(n);

    queue<tuple<int,int,int>> q;
    memset(dist, -1, sizeof(dist));

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '0') {
                q.emplace(i, j, 0);
                dist[i][j][0] = 0;
            }
        }
    }
    

    while(!q.empty()) {
        auto [x, y, state] = q.front();
        q.pop();
        if(a[x][y] == '1') {
            return !(cout << dist[x][y][state] << '\n');
        }

        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(a[nx][ny] == '#') continue;
            if('a' <= a[nx][ny] && a[nx][ny] <= 'f') {
                int now = a[nx][ny] - 'a';
                int n_state = state | 1 << now;
                if(dist[nx][ny][n_state] == -1) {
                    dist[nx][ny][n_state] = dist[x][y][state] + 1;
                    q.emplace(nx, ny, n_state);
                }

            } else if('A' <= a[nx][ny] && a[nx][ny] <= 'F') {
                int now = a[nx][ny] - 'A';
                if(state & 1 << now && dist[nx][ny][state] == -1) {
                    dist[nx][ny][state] = dist[x][y][state] + 1;
                    q.emplace(nx, ny, state);
                }

            } else {
                if(dist[nx][ny][state] != -1) continue;
                dist[nx][ny][state] = dist[x][y][state] + 1;
                q.emplace(nx, ny, state);
            }
        }
    }

    cout << -1 << '\n';

    return 0;
}