#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
vector<int> g[501];
bool visited[501];
bool go(int now, int p) {
    visited[now] = true;
    bool f = true;
    for(int next : g[now]) {
       if(next == p) continue; 
       if(!visited[next]) f &= go(next, now);
       else f = false;
    }
    return f;
}
int main() {
    fastio;
    for(int TC = 1; ; TC++) {
        for(int i = 1; i <= 500; i++) g[i].clear();
        memset(visited, false, sizeof(visited));

        cin >> n >> m;
        if(n == 0 && m == 0) break;

        for(int i = 0; i < m; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            g[t1].push_back(t2);
            g[t2].push_back(t1);
        }

        int cnt = 0; 
        for(int i = 1; i <= n; i++) {
            if(!visited[i] && go(i, 0)) {
                cnt += 1;
            }
        }
        cout << "Case " << TC << ": ";
        if(cnt == 0) {
            cout << "No trees.\n";
        } else if(cnt == 1) {
            cout << "There is one tree.\n";
        } else {
            cout << "A forest of " << cnt << " trees.\n";
        }

    }    
    return 0;
}