#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int a[1001][1001];
int psum[1001][1001];
int main() {
    fastio;
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + a[i][j];
        }
    }
    while(k--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = psum[x2][y2] - psum[x2][y1 - 1] - psum[x1 - 1][y2] + psum[x1 - 1][y1 - 1];
        int cnt = (x2 - x1 + 1) * (y2 - y1 + 1);
        cout << sum / cnt << '\n';
    }
    return 0;
}