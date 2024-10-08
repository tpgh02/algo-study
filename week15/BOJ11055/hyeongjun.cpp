#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n), ans(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        ans[i] = a[i];
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i]) {
                ans[i] = max(ans[j] + a[i], ans[i]);
            }
        }
    }

    int mx = -1;
    for(int i = 0; i < n; i++) {
        mx = max(mx, ans[i]);
    }
    cout << mx << '\n';

    
    return 0;
}