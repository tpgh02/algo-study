#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> g[51];
int x;
int go(int now) {
    if(now == x) return 0;
    if(g[now].size() == 0 || (g[now].size() == 1 && g[now][0] == x)) {
        return 1;
    }
    int ret = 0;
    for(int next : g[now]) {
        ret += go(next);
    }
    return ret;
}
int main() {
    fastio;
    int n; cin >> n;

    int root;
    for(int i = 0; i < n; i++) {
        int p; cin >> p;

        if(p == -1) {
            root = i;
            continue;
        }

        g[p].push_back(i);
    }
    cin >> x;

    cout << go(root) << '\n';
    return 0;
}