#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
char op[10];
vector<string> ans;
bool visited[10];
void go(int now, string str) {
    if(now == n + 1) {
        ans.push_back(str);
        return ;
    }

    if(now == 0) {
        for(int i = 0; i <= 9; i++) {
            str += char('0' + i);
            visited[i] = true;
            go(now + 1, str);
            str.pop_back();
            visited[i] = false;
        }
    } else {
        int prev = str.back() - '0';
        if(op[now - 1] == '<') {
            for(int i = prev + 1; i <= 9; i++) {
                if(visited[i]) continue;
                str += char('0' + i);
                visited[i] = true;
                go(now + 1, str);
                str.pop_back();
                visited[i] = false;
            }
        } else {
            for(int i = 0; i < prev; i++) {
                if(visited[i]) continue;
                str += char('0' + i);
                visited[i] = true;
                go(now + 1, str);
                str.pop_back();
                visited[i] = false;
            }
        }
    }

}
int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> op[i];
    }
    go(0, "");
    cout << ans.back() << '\n';
    cout << ans[0] << '\n';

    return 0;
}