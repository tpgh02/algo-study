#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
string str, a[101];
int n, dp[101];
int main() {
    fastio;
    cin >> str >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int strsz = str.size();
    dp[0] = 1;
    for(int i = 1; i <= strsz; i++) {
        for(int j = 0; j < n; j++) {
            int entrysz = a[j].size();
            if(i - entrysz < 0 || dp[i - entrysz] == 0) continue;
            bool f = true;
            for(int k = i - entrysz; k < i; k++) {
                if(str[k] != a[j][k - (i - entrysz)]) {
                    f = false;
                    break;
                }
            }
            if(f) {
                dp[i] = 1;
            }
        }
    }
    cout << dp[strsz] << '\n';

    return 0;
}