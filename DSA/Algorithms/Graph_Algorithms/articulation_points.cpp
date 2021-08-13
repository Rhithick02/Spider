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

void dfs(vector <int> ar[], int s, vector <int>& disc, vector <int>& low, vector <int>& parent, vector <bool>& ap) {
    static int time = 0;
    disc[s] = disc[low] = time++;
    int children = 0;
    for(auto it: ar[s]) {
        if(disc[it] == -1) {
            parent[it] = s;
            children++;
            dfs(ar, it, disc, low, parent, ap);
            low[s] = min(low[s], low[it]);
            if(parent[s] == -1 && children > 1) {
                ap[s] = true;
            } else if(parent[s] != -1 && low[it] >= disc[s]) {
                
            }
        } else if(parent[s] != it) { // Back edge and ignoring child - parent back edge
            low[s] = min(low[s], disc[it]);
        }
    }
}
void find_ap(vector <int> ar[], int n) {
    vector <bool> ap(n+1, false);
    vector <int> disc(n+1, -1), low(n+1, -1), parent(n+1, -1);
    for(int i = 1; i <= n; i++) {
        if(disc[i] == -1) {
            dfs(ar, i, disc, low, parent, ap);
        }
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
    find_ap(ar, n);
}