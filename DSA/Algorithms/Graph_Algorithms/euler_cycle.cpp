#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define lli long long
#define fi first
#define se second
#define mod 1000000007
#define MAX 100001
#define pb push_back
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

set <pair <int, int>> bridges;
map <pair<int, int>, int> mp;
bool check(vector <int> ar[], int s, int to) {
    int cnt = 0;
    for(auto it : ar[s]) {
        if(mp[{s, it}] != -1) {
            cnt++;
        }
    }
    if(cnt == 1 || (bridges.find({s, to}) == bridges.end() && bridges.find({to, s}) == bridges.end())) {
        return true;
    }
    return false;
}
void dfs(vector <int> ar[], int s, vector<bool>& vi, bool& x, int& y) {
    vi[s] = true;
    if(ar[s].size() & 1) {
        y++;
        x = true;
    }
    for(auto it: ar[s]) {
        if(vi[it]) continue;
        dfs(ar, it, vi, x, y);
    }
}
void dfs2(vector <int> ar[], int s, vector <int>& disc, vector <int>& low, int p = -1) {
    static int timer = 0;
    disc[s] = low[s] = timer++;
    for(auto to: ar[s]) {
        if(to == p) continue;
        if(disc[to] != -1) {
            low[s] = min(low[s], disc[to]);
        } else {
            dfs2(ar, to, disc, low, s);
            low[s] = min(low[s], low[to]);
            if(low[to] > low[s]) {
                bridges.insert({s, to});
            }
        }
    }
}
void dfs3(vector <int> ar[], int s) {
    for(auto& to: ar[s]) {
        if((mp[{s, to}] != -1) && check(ar, s, to)) {
            cout << s << " " << to << "\n";
            mp[{s, to}] = mp[{to, s}] = -1;
            dfs3(ar, to);
        }
    }
}
int check_euler(vector <int> ar[], int n) {
    vector <bool> vi(n+1, false);
    int nonzero_deg = 0, odd_deg = 0;
    for(int i = 1; i <= n; i++) {
        if(vi[i]) continue;
        bool ok = false;
        dfs(ar, i, vi, ok, odd_deg);
        if(ok) nonzero_deg++;
    }
    if(!nonzero_deg || (nonzero_deg == 1 && odd_deg == 0)) {
        return 0;
    } else if(nonzero_deg == 1 && odd_deg == 2){
        return 1;
    } else {
        return -1;
    }
}
void find_bridges(vector <int> ar[], int n) {
    vector <int> disc(n+1, -1), low(n+1, -1);
    for(int i = 1; i <= n; i++) {
        if(disc[i] == -1) {
            dfs2(ar, i, disc, low);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector <int> ar[n+1];
    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        ar[u].pb(v); ar[v].pb(u);
        mp[{u, v}] = 1, mp[{v, u}] = 1;
    }
    int fl = check_euler(ar, n);
    if(fl == -1) {
        cout << "The graph is not a euler graph";
    } else {
        find_bridges(ar, n);
        int st = 1;
        for(int i = 1; i <= n; i++) {
            if(ar[i].size() & 1) {
                st = i;
                break;
            }
        }
        if(fl == 1) cout << "Euler path\n";
        else cout << "Euler cycle\n";
        dfs3(ar, st);
    }
}