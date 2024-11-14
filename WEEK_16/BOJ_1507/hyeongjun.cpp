#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int a[21][21];
bool check[21][21];
int main() {
    fastio;
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
     
    bool f = true;
    for(int x = 1; x <= n; x++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j || i == x || x == j) continue;
                if(a[i][x] + a[x][j] < a[i][j]) f = false;
                if(a[i][x] + a[x][j] == a[i][j]) {
                    check[i][j] = true;
                }
            }
        }
    }

    if(!f) {
        cout << -1 << '\n';
    } else {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                if(!check[i][j]) ans += a[i][j];
            }
        }
        cout << ans << '\n';
    }

    return 0;
}