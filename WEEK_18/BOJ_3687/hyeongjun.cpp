#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
// 자릿수가 일단 작아야 함.
// 최대 자리가 제일 작아야 함.
// 1, 2, 4, 6, 7, 8, 0,
// 2, 5, 4, 6, 3, 7, 6, 
ll dp[101];
void init_min() {
    vector<pair<ll, int>> pos{{1, 2}, {2, 5}, {4, 4}, {6, 6},
                              {7, 3}, {8, 7}, {0, 6}};
    dp[0] = 0;
    dp[1] = 1e17;
    for(int i = 2; i <= 100; i++) {
        dp[i] = 1e17;
        for(auto &[num, cost] : pos) {
            if(i - cost >= 0) {
                if(num == 0 && dp[i - cost] == 0) continue;
                dp[i] = min(dp[i],  dp[i - cost] * 10LL + num);
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    cout << dp[n];
    cout << ' ';
    if(n % 2 == 0) {
        for(int i = 0; i < n / 2; i++) {
            cout << 1;
        }
    } else {
        cout << 7;
        for(int i = 0; i < (n - 3) / 2; i++) {
            cout << 1;
        }
    }
    cout << '\n';
}

int main() {
    fastio;
    init_min();
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}