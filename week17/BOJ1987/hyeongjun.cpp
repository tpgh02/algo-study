#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n, m;
string a[20];
set<int> st[20][20];
int dist[20][20];
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    queue<tuple<int,int,int>> q;
    q.push({0, 0, 1 << (a[0][0] - 'A')});
    st[0][0].insert(1 << (a[0][0] -'A'));
    dist[0][0] = 1;

    int ans = 1;
    while(!q.empty()) {
        auto [x, y, state] = q.front();
        q.pop();
        for(int k =0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            int c = a[nx][ny] - 'A';
            if(state & 1 << c) continue;
            int nstate = state | 1 << c;
            if(st[nx][ny].count(nstate)) continue;
            
            st[nx][ny].insert(nstate);
            dist[nx][ny] = max(dist[nx][ny], dist[x][y] + 1);
            ans = max(ans, dist[nx][ny]);
            q.emplace(nx, ny, nstate);
        }
    }
    cout << ans << '\n';
    
     
    return 0;
}