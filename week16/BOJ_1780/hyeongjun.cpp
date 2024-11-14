#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int ans[3];
vector<vector<int>> a;
void go(int x, int y, int k) {
    if(k == 1) {
        ans[a[x][y]] += 1;
        return ;
    }
    bool f = true;
    int st = -1;
    [&] () {
        for(int r = x; r < x + k; r++) {
            for(int c = y; c < y + k; c++) {
                if(st == -1) {
                    st = a[r][c];
                } else if(st != a[r][c]) {
                    f = false;
                    return;
                }
            }
        }
    } ();

    if(f) {
        ans[st] += 1;
    } else {
        for(int i = 0; i < 9; i++) {
            int t1 = i / 3;
            int t2 = i % 3; 
            go(x + t1 * (k / 3), y + t2 * (k / 3), k / 3);
        }
    }
    return ;
}
int main() {
    fastio;
    int n; cin >> n;
    a.resize(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j] += 1;
        }
    }

    go(0, 0, n);
    for(int i = 0; i < 3; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}