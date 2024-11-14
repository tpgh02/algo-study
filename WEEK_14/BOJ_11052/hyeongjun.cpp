#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dp[1001];
int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i - j < 0) break;
            dp[i] = max(dp[i], dp[i - j] + a[j]);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}