#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dp[1001][1001];
int mod =10007;
int go(int n, int k) {
    if(k == 0 || n == k) return 1;
    int &ret = dp[n][k];
    if (ret != -1) {
        return ret;
    }
    ret = go(n  - 1, k - 1) + go(n - 1, k);
    ret %= mod;
    return ret;
}
int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    cout << go(n, k) << '\n';
    return 0;
}