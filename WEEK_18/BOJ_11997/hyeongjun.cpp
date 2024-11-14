#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int n; cin >> n;
    vector<pii> a(n);
    vector<int> xpos, ypos;
    for(auto &[x, y] : a) {
        cin >> x >> y;
        xpos.push_back(x);
        ypos.push_back(y);
    }
    sort(xpos.begin(), xpos.end());
    xpos.erase(unique(xpos.begin(), xpos.end()), xpos.end());
    sort(ypos.begin(), ypos.end());
    ypos.erase(unique(ypos.begin(), ypos.end()), ypos.end());

    int r = xpos.size();
    int c = ypos.size();
    vector<vector<int>> psum(r + 1, vector<int>(c + 1, 0));

    for(auto &[x, y] : a) {
        x = lower_bound(xpos.begin(), xpos.end(), x) - xpos.begin();
        y = lower_bound(ypos.begin(), ypos.end(), y) - ypos.begin();
        psum[x + 1][y + 1] = 1;
    }

    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            psum[i][j] += psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
        }
    }

    int ans = 1e9;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            int t1 = psum[i][j];
            int t2 = psum[i][c] - t1;
            int t3 = psum[r][j] - t1;
            int t4 = psum[r][c] - t1 - t2 - t3;
            ans = min(ans, max({t1, t2, t3, t4}));
        }
    }
    cout << ans << '\n';

    return 0;
}