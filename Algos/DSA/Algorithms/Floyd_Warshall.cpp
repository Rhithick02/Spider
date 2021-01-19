#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
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
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

int main(){
    ios::sync_with_stdio(false);
    int n, u, v, w;
    cin >> n;
    vector <pair<int, int>> ed[n+1];
    vector <vector <int>> d(n+1, vector<int> (n+1, mod));
    For(i, 0, n) {
        cin >> u >> v >> w;
        ed[u].pb({v, w});
        ed[v].pb({u, w});
    }
    For(i, 1, n+1) {
        for(auto it: ed[i]) {
            d[i][it.fi] = it.se;
        }
        d[i][i] = 0;
    }
    For(i, 1, n+1) {
        For(j, 1, n+1) {
            For(k, 1, n+1) {
                d[j][k] = min(d[j][k], d[j][i]+d[i][k]);
            }
        }
    }
    For(i, 1, n+1) {
        For(j, 1, n+1) {
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }
}