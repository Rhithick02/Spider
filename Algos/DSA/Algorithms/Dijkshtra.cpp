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
    int n, s, u, v, w;
    cin >> n >> s;
    vector <pair<int, int>> ed[n+1];
    vector <int> d(n+1, mod);
    vector <bool> processed(n+1);
    priority_queue <pair<int, int>, vector <pair<int, int>>> q;
    For(i, 0, n) {
        cin >> u >> v >> w;
        ed[u].pb({v, w});
        ed[v].pb({u, w});
    }
    d[s] = 0;
    q.push({0, s});
    while(!q.empty()) {
        pair <int, int> top = q.top();
        q.pop();
        if(processed[top.se]) continue;
        processed[top.se] = true;
        for(auto to: ed[top.se]) {
            if(d[top.se] + to.se < d[to.fi]) {
                d[to.fi] = d[top.se] + to.se;
                q.push({-d[to.fi], to.fi});
            }
        }
    }
    For(i, 1, n+1) cout << d[i] << " ";
    cout << "\n";
}