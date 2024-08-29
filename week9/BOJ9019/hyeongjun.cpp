#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int multi_two(int now) {
    now *= 2;
    now %= 10000;
    return now;
}
int minus_one(int now) {
    if(now == 0) return 9999;
    return now - 1;
}
int left(int now) {
    int l = now / 1000;
    now *= 10;
    now += l;
    now %= 10000;
    return now;
}
int right(int now) {
    int r = now % 10;
    now /= 10;
    now += r * 1000;
    return now;
}

int p[10000];
char pc[10000];

int main() {
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int st, ed;
        cin >> st >> ed;
        memset(pc, 0, sizeof(pc));
        memset(p, 0, sizeof(p));
        queue<int> q;
        q.push(st);
        while(!q.empty()) {
            int now = q. front();
            if(now == st) break;
            q.pop();

            int mt = multi_two(now);
            int m1 = minus_one(now);Q
            int lt = left(now);
            int rt = right(now);

            if (p[mt] == -1) {
                q.push(mt);
                p[mt] = now;
                pc[mt] = 'D';
            }

            if (p[m1] == -1) {
                q.push(m1);
                p[m1] = now;
                pc[m1] = 'S';
            }
            if (p[lt] == -1) {
                q.push(lt);
                p[lt] = now;
                pc[lt] = 'L';
            }
            if (p[rt] == -1) {
                q.push(rt);
                p[rt] = now;
                pc[rt] = 'R';
            }
        }

        stack<char> stk;
        while(ed != st) {
            stk.push(pc[ed]);
            ed = p[ed];
        }
        while(!stk.empty()) {
            cout << stk.top();
            stk.pop();
        }
        cout << '\n';
    }
    return 0;
}
