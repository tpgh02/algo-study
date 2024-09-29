#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
bool check[1000001];
bool p[1100000];
int main() {
    fastio;
    ll l, r;
    cin >> l >> r;
    vector<ll> prime;
    ll sqrtr = ll(ceil(sqrt(r)));
    for(ll i = 2; i <= sqrtr; i++) {
        if(!p[i]) {
            prime.push_back(i);
            for(ll j = i * i; j <= sqrtr; j += i) {
                p[j] = true;
            }
        }
    }

    for(ll i : prime) {
        ll now = i * i;
        ll remain = l % now;
    
        ll s = now - remain;
        if(s == now) s = 0LL;
        for(; s <= r - l; s += now) {
            check[s] = true;
        }
    }

    int ans = 0;
    for(int i = 0; i <= r - l; i++) {
        ans += !check[i];
    }
    cout << ans << '\n';

    return 0;
}