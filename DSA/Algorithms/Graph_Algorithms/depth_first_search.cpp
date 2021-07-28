/* One of the graph traversal methods.*/
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

void dfs(vector<int> ar[], vector <bool>& vi, int s) {
    vi[s] = true;
    cout << s << " ";
    for(auto it: ar[s]) {
        if(vi[it]) continue;
        dfs(ar, vi, it);
    }
}

int main() {
    int n, m, root;
    cin >> n >> m >> root;
    vector <int> ar[n+1];
    vector <bool> vi(n+1, false);
    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        ar[u].push_back(v);
        ar[v].push_back(u);
    }
    dfs(ar, vi, root);
}