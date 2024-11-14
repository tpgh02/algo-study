#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dep[10001][2];
int g[10001][2];
int cnt = 1;
bool visited[10001];
void go(int now, int depth) {
    if(now == -1) return ;
    go(g[now][0], depth + 1);
    dep[depth][0] = min(dep[depth][0], cnt);
    dep[depth][1] = max(dep[depth][1], cnt);
    cnt += 1;
    go(g[now][1], depth + 1);
}
bool check[10001];
int main() {
    fastio;
    int n; cin >> n;
    for(int i = 1; i < 10001; i++) {
        dep[i][0] = 1e9;
    }

    for(int i = 1; i <= n; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1][0] = t2;
        g[t1][1] = t3;
        if(t2 != -1) check[t2] = true;
        if(t3 != -1) check[t3] = true;
    }

    int root;
    for(int i = 1; i <= n; i++) {
        if(!check[i]) root = i;
    }
    go(root, 1);

    int idx = -1;
    int ans = -1;
    for(int i = 1; i < 10001; i++) {
        int now = dep[i][1] - dep[i][0] + 1;
        if(ans < now) {
            ans = now;
            idx = i;
        }
    }
    cout << idx << ' ' << ans << '\n';

    return 0;
}