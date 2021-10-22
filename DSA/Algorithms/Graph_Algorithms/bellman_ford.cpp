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
    int n, m;
    bool ok;
    cin >> n >> m;
    vector <pair<pair<int, int>, int>> ar(m);
    vector <int> dist(n+1, mod);
    dist[1] = 0;
    for(int i = 0; i < m; i++) {
        cin >> ar[i].fi.fi >> ar[i].fi.se >> ar[i].se;
    }
    for(int i = 0; i < n; i++) {
        ok = false;
        for(int j = 0; j < m; j++) {
            if(dist[ar[j].fi.fi] < mod) {
                dist[ar[j].fi.se] = min(dist[ar[j].fi.se], ar[j].se + dist[ar[j].fi.fi]);
                ok = true;
            }
        }
    }
    if(ok) {
        cout << "Negative cycle detected\n";
        exit(0);
    }
    for(int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
}