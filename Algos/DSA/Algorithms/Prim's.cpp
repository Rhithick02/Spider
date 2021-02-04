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

int main() {
    ios::sync_with_stdio(false);
    int n, m, u, v, w, cost = 0;
    cin >> n >> m;

    vector <pair<int, int>> edge[n+1], min_edge(n+1, {mod, -1});
    vector <bool> vi(n+1, false);
    set <pair<int, int>> st;

    For(i, 0, m) {
        cin >> u >> v >> w;
        edge[u].pb({v, w});
        edge[v].pb({u, w});
    }
    
    /* min_edge[v] = {w, u} represents
    edge from non selected node v to a selected node u carrying a weight w */

    min_edge[1].fi = 0;
    st.insert({0, 1});

    For(i, 1, n+1) {
        int node = (*st.begin()).se;
        cost += (*st.begin()).fi;
        vi[node] = true;
        st.erase(st.begin());

        // Path
        if(min_edge[node].se != -1) {
            cout << node << " " << min_edge[node].se << "\n";
        }

        for(auto it: edge[node]) {
            if(!vi[it.fi] && it.se < min_edge[it.fi].fi) {
                st.erase({min_edge[it.fi].fi, it.fi});
                min_edge[it.fi] = {it.se, node};
                st.insert({it.se, it.fi});
            }
        }
    }
    cout << cost << endl;
}