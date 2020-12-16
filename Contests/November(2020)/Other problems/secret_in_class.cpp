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
#define MAX 100001
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
lli cost, cnt;
int n, m, q, p, u, v;
vector <int> ar[MAX];
vector <bool> vi(MAX);
void dfs(int st) {
    cnt++;
    vi[st] = true;
    for(auto it: ar[st]) {
        if(vi[it]) continue;
        dfs(it);
    }
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        For(i, 0, MAX) {
            ar[i].clear();
            vi[i] = false;
            cost = 0;
        }
        cin >> n >> m >> q >> p;
        For(i, 0, m) {
            cin >> u >> v;
            ar[u].pb(v);
            ar[v].pb(u);
        }
        if(p > q) {
            cout << 1LL * q * n << "\n";
        } else {
            For(i, 1, n + 1) {
                if(!vi[i]) {
                    cost += q;
                    dfs(i);
                    cost += 1LL * (cnt - 1) * p;
                    cnt = 0;
                }                
            }
            cout << cost << "\n";
        }
    }
}