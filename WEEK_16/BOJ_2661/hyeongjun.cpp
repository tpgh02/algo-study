#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
bool check(string &str) {
    int sz = str.size();
    int half_sz = sz / 2;
    for(int i = 1; i <= half_sz; i++) {
        for(int k = 0; k + i * 2 <= sz; k++) {
            if(str.substr(k, i) == str.substr(k + i, i)) {
                return false;
            }
        }
    }
    return true;
}
string ans;
bool go(int idx, string str) {
    if(idx == n) {
        ans = str;
        return true;
    }

    for(char i = '1'; i <= '3'; i++) {
        string next_str = str + i;
        if(check(next_str) && go(idx + 1, next_str)) {
            return true;
        }
    }
    return false;
}
int main() {
    fastio;
    cin >> n;
    go(0, "");
    cout << ans << '\n';
    return 0;
}