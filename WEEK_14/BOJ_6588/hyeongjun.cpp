#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
bool p[1000001];
int main() {
    fastio;
    vector<int> prime;
    for(int i = 2; i <= 1000000; i++) {
        if(!p[i]) {
            prime.push_back(i);
            for(int j = i + i; j <= 1000000; j += i) {
                p[j] = true;
            }
        }
    }
    while(true) {
        int n; cin >> n;
        if(n == 0) break;
        for(int x : prime) {
            if(!p[n - x]) {
                cout << n << " = " << x << " + " << n - x << '\n';
                break;
            }
        }
    }
    return 0;
}