#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define For(i, n) for (int i = 0; i < n; i++)
#define asc(x) x.begin(), x.end()
#define des(x) x.rbegin(), x.rend()
#define pb push_back
#define fi first
#define se second

vector <string> s;
queue <pair<int, int>> q;
int n, fl, r[2], c[2];
bool check(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n;
}
void check_places(int dx[], int dy[], vector <pair<int, int>>& present) {
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (abs(i - j) != 1 || !check(cur.fi + dx[i], cur.se + dy[j]))
                    continue;
                int x = cur.fi + dx[i], y = cur.se + dy[j];
                if (s[x][y] == '0') {
                    q.push({x, y});
                    present.pb({x, y});
                    s[x][y] = 1;
                }
            }
        }
    }
}
int main() {
    string te;
    cin >> n;    
    cin >> r[0] >> c[0] >> r[1] >> c[1];
    For(i, n) {
        cin >> te;
        s.pb(te);
    }
    int dx[] = {-1, 0, 1}, dy[] = {-1, 0, 1};
    vector <pair<int, int>> forw, rev;
    forw.pb({r[0] - 1, c[0] - 1});
    rev.pb({r[1] - 1, c[1] - 1});
    q.push({r[0] - 1, c[0] - 1});
    check_places(dx, dy, forw);
    q.push({r[1] - 1, c[1] - 1});
    check_places(dx, dy, rev);
    int mini = 1e9;
    for (int i = 0; i < forw.size(); i++) {
        for (int j = 0; j < rev.size(); j++) {
            int xdist = forw[i].fi - rev[j].fi;
            int ydist = forw[i].se - rev[j].se;
            mini = min(mini, xdist * xdist + ydist * ydist);
        }
    }
    cout << mini << endl;
}