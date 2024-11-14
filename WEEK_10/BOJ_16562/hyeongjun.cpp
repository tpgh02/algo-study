#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, k;
int p[10001];
bool check[10001];
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
void set_union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return ;
    if(p[x] < p[y]) {
        p[x] = y;
    } else {
        p[y] = x;
    }
}
int main() {
    fastio;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        p[i] *= -1;
    }
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        set_union(t1, t2);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int x = find(i);
        if(check[x]) continue;
        check[x] = true;
        ans -= p[x];
    }

    if(ans > k) {
        cout << "Oh no" << '\n';
    } else {
        cout << ans << '\n';
    }
    
    return 0;
}