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

vector <int> flat_tree;
void dfs(vector <int> ar[], int s, vector <int>& tin, vector <int>& tout) {
    static int timer = 0;
    tin[s] = timer++;
    flat_tree.pb(s);
    for(auto to: ar[s]) {
        if(tin[to] != -1) continue;
        dfs(ar, to, tin, tout);
    }
    flat_tree.pb(s);
    tout[s] = timer++;
}
int main() {
    int n;
    cin >> n;
    vector <int> ar[n+1], tin(n+1, -1), tout(n+1, -1);
    for(int i = 0, u, v; i < n-1; i++) {
        cin >> u >> v;
        ar[u].pb(v);
        ar[v].pb(u);
    }
    // Rooted at 1
    dfs(ar, 1, tin, tout);
    cout << "Flattened tree\n";
    for(auto it: flat_tree) {
        cout << it << " ";
    }
    cout << "\nEntry time\n";
    for(int i = 1; i <= n; i++) {
        cout << tin[i] << " ";
    }
    cout << "\nExit time\n";
    for(int i = 1; i <= n; i++) {
        cout << tout[i] << " ";
    }

}