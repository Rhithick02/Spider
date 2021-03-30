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

vector <int> top_sort;
vector <int> ar[MAX];
vector <bool> vi(MAX);
void dfs(int node) {
    vi[node] = true;
    for(auto it: ar[node]) {
        if(vi[it]) {
            continue;
        }
        dfs(it);
    }
    top_sort.pb(node);
    return;
}

int main(){
    ios::sync_with_stdio(false);
    int n, m, u, v;
    cin >> n >> m;
    For(i, 0, m) {
        cin >> u >> v;
        ar[u].pb(v);
    }
    For(i, 1, n+1) {
        if(!vi[i]) {
            dfs(i);
        }
    }
    reverse(asc(top_sort));
    for(auto it: top_sort) {
        cout << it << " ";
    }
    cout << "\n";
}