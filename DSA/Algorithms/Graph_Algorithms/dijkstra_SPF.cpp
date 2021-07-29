/* Find the shortest path from one node to all other nodes. */
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

int main() {
    int n, m, root;
    cin >> n >> m >> root;
    vector <pair<int, int>> ar[n+1];
    vector <int> distance(n+1, mod);
    set <pair<int, int>> store;
    vector <bool> vi(n+1, false);
    for(int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v;
        ar[u].push_back({v, w});
        ar[v].push_back({u, w});
    }
    distance[root] = 0;
    store.insert({0, root});
    for(int i = 0; i < n;) {
        pair <int, int> cur = *store.begin();
        store.erase(store.begin());
        if(vi[cur.se]) continue;
        vi[cur.se] = true;
        for(auto it: ar[cur.se]) {
            if(distance[it.fi] > cur.fi + it.se) {
                distance[it.fi] = cur.fi + it.se;
                store.insert({distance[it.fi], it.fi});
            }
        }
        i++;
    }
    for(int i = 1; i <= n; i++) {
        cout << distance[i] << " ";
    }
}