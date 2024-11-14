#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int p[100001];
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
void set_union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        p[x] = y;
    }
    return ;
}
int main() {
    fastio;
    cin >> n >> m;
    memset(p, -1, sizeof(p));
    vector<tuple<int, int, int>> a(m);
    for(auto &[t3, t1, t2] : a) {
        cin >> t1 >> t2 >> t3;
    }
     
    sort(a.begin(), a.end());
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < m; i++) {
        if(cnt == n - 1) break;
        auto [t3, t1, t2] = a[i];
        int x = t1, y = t2;
        t1 = find(t1);
        t2 = find(t2);
        if(t1 != t2) {
            cout << x << ' ' << y << ' ' << t3  << '\n';
            set_union(t1, t2);
            ans += t3;
            cnt += 1;
        }
    }
    cout << ans << '\n';
    return 0;
}