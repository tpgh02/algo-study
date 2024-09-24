#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, k;
int mod = 1e9;
int dp[201][201];
int go(int val, int cnt) {
    if(cnt == 0) {
        if(val == 0) return 1;
        return 0;
    }

    int &ret = dp[val][cnt];
    if(ret != -1) {
        return ret;
    }
    ret = 0;
    for(int i = 0; i <= val; i++) {
        ret += go(val - i, cnt - 1);
        ret %= mod;
    }
    return ret;
}
int main() {
    fastio;
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    cout << go(n, k) << '\n';
    return 0;
}