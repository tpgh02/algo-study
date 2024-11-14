#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, k;
int dp[10001];
int a[100];
int main() {
    fastio;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i <= k; i++) {
        dp[i] = 1e9;
        for(int j = 0; j < n; j++) {
            if(i - a[j] < 0) continue;
            dp[i] = min(dp[i], dp[i - a[j]] + 1);
        }
    }
    
    if(dp[k] == 1e9) cout << -1 << '\n';
    else cout << dp[k] << '\n';

    return 0;
}