#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int dist[50][50];
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<string> a(n);

    int ex, ey;
    ex = ey = -1;
    memset(dist, -1, sizeof(dist));
    queue<pii> wa, q;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '*') {
                wa.emplace(i, j);
            } else if(a[i][j] == 'D') {
                ex = i;
                ey = j;
            } else if(a[i][j] == 'S') {
                q.emplace(i, j);
                dist[i][j] = 0;
            }
        }
    }
    while(true) {
        int wa_size = wa.size();
        for(int i = 0; i < wa_size; i++) {
            auto [x, y] = wa.front();
            wa.pop();
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(a[nx][ny] == 'X') continue;
                if(a[nx][ny] == '.' || a[nx][ny] == 'S') {
                    a[nx][ny] = '*';
                    wa.emplace(nx, ny);
                }
            }
        }

        int q_size = q.size();
        if(q_size == 0) {
            return !(cout << "KAKTUS" << '\n');
        }
        for(int i = 0; i < q_size; i++) {
            auto [x, y] = q.front();
            q.pop();
            if(x == ex && y == ey) {
                return !(cout << dist[x][y] << '\n');
            }
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(a[nx][ny] == 'X') continue;
                if(a[nx][ny] != '*' && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.emplace(nx, ny);
                }
            }
        }


    }

    return 0;
}