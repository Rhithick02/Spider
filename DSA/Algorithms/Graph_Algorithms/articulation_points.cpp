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

void dfs(vector <int> ar[], int s, vector <int>& disc, vector <int>& low, vector 
                                                        <bool>& ap, int p = -1) {
    static int time = 0;
    disc[s] = low[s] = time++;
    int children = 0;
    for(auto it: ar[s]) {
        if(it == p) continue;
        if(disc[it] != -1) {
            low[s] = min(low[s], disc[it]);
        } else {
            dfs(ar, it, disc, low, ap, s);
            children++;
            low[s] = min(low[s], low[it]);
            if(low[it] >= disc[s] && p != -1) {  // Case 2 if AP is not a root and ignoring back edges
                ap[s] = true;
            }
        }
        if(p == -1 && children > 1) {   // Case - 1 if AP is a root
            ap[s] = true;
        }
    }
}
void find_ap(vector <int> ar[], int n) {
    vector <bool> ap(n+1, false);
    vector <int> disc(n+1, -1), low(n+1, -1);
    for(int i = 1; i <= n; i++) {
        if(disc[i] == -1) {
            dfs(ar, i, disc, low, ap);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(ap[i] == true) {
            cout << i << " ";
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