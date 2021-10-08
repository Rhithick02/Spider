#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define lli long long
#define fi first
#define se second
#define mod 1000000007
#define MAX 100001
#define pb push_back
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector <vector <lli>> dist(n+1, vector <lli>(n+1, 1ll*1000000*mod));
    for(int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        dist[u][v] = w;
        dist[v][u] = w;
    }
    for(int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << (dist[u][v] == 1ll*1000000*mod ? -1 : dist[u][v]) << "\n";
    }
}