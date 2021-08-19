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

vector <pair <int, int>> ans;
void dfs(int s, vector <int> ar[], vector <int>& disc, vector <int>& low, int p = -1) {
    static int timer = 0;
    disc[s] = low[s] = timer++;
    for(auto it: ar[s]) {
        if(it == p) continue;
        if(disc[it] != -1) {
            low[s] = min(low[s], disc[it]);
        } else {
            dfs(it, ar, disc, low, s);
            low[s] = min(low[s], low[it]);
            if(low[it] > disc[s]) {
                ans.pb({s, it});
            }
        }
    }
}                                                                           

void find_bridges(vector <int> ar[], int n) {
    vector <int> disc(n+1, -1), low(n+1, -1);
    for(int i = 1; i <= n; i++) {
        if(disc[i] != -1) continue;
        dfs(i, ar, disc, low);
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector <int> ar[n+1];
    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        ar[u].pb(v);
        ar[v].pb(u);
    }
    find_bridges(ar, n);
    for(auto it: ans) {
        cout << it.fi << " " << it.se << "\n";
    }
}