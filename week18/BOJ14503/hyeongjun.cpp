#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
// 북 동 남 서
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int a[50][50];
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    int x, y, dir;
    cin >> x >> y >> dir;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    while(true) {
        if(a[x][y] == 1) break;
        if(a[x][y] == 0) {
            a[x][y] = -1;
            ans += 1;
        } else {
            bool f = false;
            for(int k = 1; k < 5; k++) {
                int ndir = (dir - k + 4) % 4;
                int nx = x + dx[ndir];
                int ny = y + dy[ndir];
                if(a[nx][ny] == 1) continue;
                if(a[nx][ny] == 0) {
                    x = nx;
                    y = ny;
                    dir = ndir;
                    f = true;
                    break;
                }
            }
            if(!f) {
                int ndir = (dir + 2) % 4;
                x = x + dx[ndir];
                y = y + dy[ndir];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}