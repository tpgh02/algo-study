#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    ll n;
    int k;
    cin >> n >> k;

    ll s = 1, e = n * n;
    ll ans = -1;

    while(s <= e) {
        ll mid = (s + e) / 2;
        
        ll cnt = 0;
        for(ll i = 1; i <= n; i++) {
            cnt += min(n, (mid - 1LL) / i);
        }

        if(cnt >= k) {
            e = mid - 1;
        } else {
            bool f = false;
            for(ll i = 1; i <= n; i++) {
                if(mid % i == 0 && mid / i <= n) {
                    f = true;
                    break;
                }
            }
            if(f) ans = mid;
            s = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}

// 1 2 3
// 2 4 6
// 3 6 9