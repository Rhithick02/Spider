/* Detect cycles in a directed graph
    0 - Not visited
    1 - Processing
    2 - Processed */
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define lli long long
#define For(i,a,n) for(int i=(a);i<n;i++)
#define asc(x) x.begin(),x.end()
#define des(x) x.rbegin(),x.rend()
#define pb push_back
#define fi first
#define se second
#define mod 1000000007
#define MAX 100001
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

bool is_cycle(vector <int> ar[], vector <int>& vi, int node) {
    vi[node] = 1;
    for(auto it: ar[node]) {
        if(vi[it] == 1 || (vi[it] == 0 && is_cycle(ar, vi, it))) {
            return true;
        }
    }
    vi[node] = 2;
    return false;
}
int main() {
    int n, m, root;
    cin >> n >> m >> root;
    vector <int> ar[n+1], vi(n+1, 0);
    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        ar[u].push_back(v);
        ar[v].push_back(u);
    }
    if(is_cycle(ar, vi, root)) {
        cout << "Cycle detected !!\n";
    } else {
        cout << "No cycle detected\n";
    }
}