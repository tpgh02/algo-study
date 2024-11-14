#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    for(int &x : a) cin >> x;
    sort(a.begin(), a.end());

    int s = 1, e = 1e9;
    int ans = -1;

    while(s <= e) {
        int mid = (s + e) / 2;

        int cnt = 1;
        int last = a[0];
        for(int i = 1; i < n; i++) {
            if(a[i] - last >= mid) {
                cnt += 1;
                last = a[i];
            }
        }
        if(cnt >= c) {
            s = mid + 1;
            ans = mid;
        } else {
            e = mid - 1;
        }
    }
    cout << ans << '\n';

    return 0;
}