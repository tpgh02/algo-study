#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
bool a[201][201];
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(i == j) a[i][j] = true;
        }
    }
    vector<int> pos(m);
    for(int &x : pos) cin >> x;
    for(int i = 1; i <= n; i++) {
        for(int x = 1; x <= n; x++) {
            for(int y = 1; y <= n; y++) {
                if(x == y || x == i || y == i) continue;
                if(a[x][i] && a[i][y]) a[x][y] = true;
            }
        }
    }

    bool f = true;
    for(int i = 0; i < m - 1; i++) {
        if(!a[pos[i]][pos[i + 1]]) f = false;
    }
    if(!a[pos[m - 1]][pos[0]]) f = false;

    if(f) cout << "YES" << '\n';
    else cout << "NO" << '\n';
     
    return 0;
}