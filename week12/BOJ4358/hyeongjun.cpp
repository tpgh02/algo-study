#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    string str;
    int cnt = 0;
    map<string, int> mp;
    while(getline(cin, str)) {
        cnt += 1;
        mp[str] += 1;
    }
    cout << fixed;
    cout.precision(4);
    for(auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << ' ';
        cout << ((double)it->second / cnt) * (double)100 << '\n';
    }
    return 0;
}