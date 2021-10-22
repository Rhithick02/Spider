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

vector <vector <int>> cycles;
void dfs(vector <int> ar[], vector <int>& col, vector <int>& par, int s, int p = 0) {
    if(col[s] == 2) {
        return;
    }
    if(col[s] == 1) {
        vector <int> cycle(1, p);
        int cur = p;
        while(cur != s) {
            cur = par[cur];
            cycle.pb(cur);
        }
        cycles.pb(cycle);
        return;
    }
    col[s] = 1;
    par[s] = p;
    for(auto it: ar[s]) {
        dfs(ar, col, par, it, s);
    }
    col[s] = 2;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector <int> ar[n+1];
    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        ar[u].pb(v);
    }
    vector <int> col(n+1, 0), par(n+1, 0);
    for(int i = 1; i <= n; i++) {
        if(col[i] == 2) continue;
        dfs(ar, col, par, i);
    }
    for(auto it: cycles) {
        for(auto ti: it) {
            cout << ti << " ";
        }
        cout << endl;
    }
}