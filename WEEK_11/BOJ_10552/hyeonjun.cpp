#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int nxt[100001];
bool visited[100001];
int main() {
    fastio;
    int n, m, k;
    cin >> n >> m >> k;
    
    for(int i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        if(nxt[t2]) continue;
        nxt[t2] = t1;
    }

    int cnt = 0;
    while(1) {
        if(visited[k]) return !(cout << -1 << '\n');
        visited[k] = true;
        if(nxt[k] == 0) break;
        k = nxt[k];
        cnt += 1;
    }
    cout << cnt << '\n';

    return 0;
}