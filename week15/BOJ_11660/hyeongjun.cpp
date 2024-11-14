#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<vector<int>> psum(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + a[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        int t1, t2, t3, t4;
        cin >> t1 >> t2 >> t3 >> t4;
        int ans = psum[t3][t4];
        ans -= psum[t1 - 1][t4];
        ans -= psum[t3][t2 - 1];
        ans += psum[t1 - 1][t2 - 1];
        cout << ans << '\n';
    }


    return 0;
}