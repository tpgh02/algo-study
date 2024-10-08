#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> g[32001];
int ind[32001];
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        ind[t2] += 1;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 1; i <= n; i++) {
        if(ind[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int now = q.top();
        q.pop();
        cout << now << ' ';
        for(int next : g[now]) {
            ind[next] -= 1;
            if(ind[next] == 0) {
                q.push(next);
            }
        }
    }
    cout << '\n';
    return 0;
}