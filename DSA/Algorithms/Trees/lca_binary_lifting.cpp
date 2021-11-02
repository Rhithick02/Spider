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

int n, l, root = 1;
vector <int> tin, tout;
void dfs(vector <int> ar[], vector <vector <int>>& parent, int s, int p) {
    static int timer = 0;
    tin[s] = timer++;
    parent[s][0] = p;
    for(auto it: ar[s]) {
        if(it == p) continue;
        dfs(ar, parent, it, s);
    }
    tout[s] = timer++;
}
bool is_ancestor(int u, int v) {
    return tin[u] < tin[v] && tout[u] > tout[v];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    l = ceil(log2(n));
    vector <int> ar[n+1];
    vector <vector <int>> parent(n+1, vector <int> (l+1, 0));
    for(int i = 0, u, v; i < n-1; i++) {
        cin >> u >> v;
        ar[u].pb(v);
        ar[v].pb(u);
    }
    tin.resize(n+1); tout.resize(n+1);
    dfs(ar, parent, root, root);
    for(int i = 1; i <= l; i++) {
        for(int j = 1; j <= n; j++) {
            parent[j][i] = parent[parent[j][i-1]][i-1];
        }
    }
    // LCA for these 2 nodes;
    int u, v;
    cin >> u >> v;
    if(is_ancestor(u, v)) {
        cout << u << "\n";
    } else if(is_ancestor(v, u)) {
        cout << v << "\n";
    } else {
        for(int i = l; i >= 0; i--) {
            if(!is_ancestor(parent[u][i], v)) {
                u = parent[u][i];
            }
        }
        cout << parent[u][0] << "\n";
    }
}