#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MAX = 1299710;
vector<int> prime;
int p[MAX];
void solve() {
    int n; cin >> n;
    if(n == 1 || p[n] == -1) cout << 0 << '\n';
    else {
        int i = lower_bound(prime.begin(), prime.end(), n) - prime.begin();
        cout << prime[i] - prime[i - 1] << '\n';
    }
}
int main() {
    fastio;
    memset(p, -1, sizeof(p));
    for(int i = 2; i < MAX; i++) {
        if(p[i] == -1) {
            prime.push_back(i);
            for(int j = i + i; j < MAX; j += i) {
                p[j] = i;
            }
        }
    }
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}