#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int a[20][20];
const int GARO = 0;
const int SERO = 1;
int check(int x1, int x2, int y1, int y2) {
    int x = 0, y = 0;
    for(int i = x1; i < x2; i++) {
        for(int j = y1; j < y2; j++) {
            if(a[i][j] == 1) x += 1;
            if(a[i][j] == 2) y += 1;
        }
    }

    if(x == 0 && y != 1) return 0;
    else if(x == 0 && y == 1) return 1;

    return 2;
}

int go(int x1, int x2, int y1, int y2, int dir) {
    int chk = check(x1, x2, y1, y2);
    if(chk == 0) return 0;
    else if(chk == 1) return 1;

    int ret = 0;
    if(dir == GARO) {
        for(int i = x1 + 1; i < x2 - 1; i++) {
            bool f1 = true;
            bool f2 = false;
            for(int j = y1; j < y2; j++) {
                if(a[i][j] == 2) f1 = false;
                if(a[i][j] == 1) f2 = true;
            }
            if(f1 && f2) {
                ret += go(x1, i, y1, y2, SERO) * go(i + 1, x2, y1, y2, SERO);
            }
        }
    } else if(dir == SERO) {
        for(int i = y1 + 1; i < y2 - 1; i++) {
            bool f1 = true;
            bool f2 = false;
            for(int j = x1; j < x2; j++) {
                if(a[j][i] == 2) f1 = false;
                if(a[j][i] == 1) f2 = true;
            }

            if(f1 && f2) {
                ret += go(x1, x2, y1, i, GARO) * go(x1, x2, i + 1, y2, GARO);
            }

        }
    }
    return ret;
}


int main() {
    fastio;
    cin >> n; 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int ans = go(0, n, 0, n, GARO) + go(0, n, 0, n, SERO);
    
    if(ans == 0) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}