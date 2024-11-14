#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
bool l[30], r[30], c[15];
int go(int now) {
    if(now == n) return 1;
    int ret = 0;
    for(int i = 0; i < n; i++) {
        if(c[i] || r[now + i] || l[i - now + 14]) continue;
        c[i] = r[now + i] = l[i - now + 14] = true;
        ret += go(now + 1);
        c[i] = r[now + i] = l[i - now + 14] = false;
    }
    return ret;
}
int main() {
    fastio;
    cin >> n;
    cout << go(0) << '\n';
    return 0;
}