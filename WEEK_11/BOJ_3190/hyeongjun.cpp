#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, k, l;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int L(int now) {
    return (now + 3) % 4;
}
int D(int now) {
    return (now + 1) % 4;
}
bool a[101][101];
char t[10001]; 
int main() {
    fastio;
    cin >> n;
    cin >> k;
    for(int i = 0; i < k; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        a[t1][t2] = true;
    }

    cin >> l;
    for(int i = 0; i < l; i++) {
        int time;
        char c;
        cin >> time >> c;
        t[time] = c;
    }

    int time = 0;
    int dir = 0;
    deque<pii> body;
    body.emplace_back(1, 1);
    for(;;) {
        auto [x, y] = body.front();

        switch (t[time]) {
            case 'L':
                dir = L(dir);
                break;
            case 'D':
                dir = D(dir);
                break;
        }

        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 1 || nx > n || ny < 1 || ny > n) {
            return !(cout << time + 1 << '\n');
        }

        body.emplace_front(nx, ny);

        for(int i = 1; i < body.size(); i++) {
            if(body[i] == body.front()) {
                return !(cout << time + 1 << '\n');
            }
        }

        if(a[nx][ny]) {
            a[nx][ny] = false;
        } else {
            body.pop_back();
        }

        time += 1;
    }
    
    return 0;
}