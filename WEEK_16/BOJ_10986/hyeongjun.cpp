#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, a[1000001];
int psum[1000001];
ll cnt[1001];
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        psum[i] = psum[i - 1] + a[i];
        psum[i] %= m;
        cnt[psum[i]] += 1;
    }

    ll ans = 0;
    for(int i = 0; i < m; i++) {
        ans += (cnt[i] * (cnt[i] - 1)) / 2LL;
    }
    ans += cnt[0];
    cout << ans << '\n';

    return 0;
}

