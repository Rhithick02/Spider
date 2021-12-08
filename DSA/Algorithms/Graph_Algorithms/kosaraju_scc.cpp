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

vector<bool> vi;
vector<int> ord;
vector<vector<int>> ar, ra, ssc;
void topsort(int s) {
    vi[s] = true;
    for (auto it: ar[s]) {
        if (vi[it]) continue;
        topsort(it);
    }
    ord.pb(s);
}
void dfs(int s, vector<int>& temp) {
    vi[s] = true;
    for (auto it : ra[s]) {
        if (vi[it]) continue;
        dfs(it, temp);
    }
    temp.pb(s);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    ar.resize(n+1);
    ra.resize(n+1);
    vi.resize(n+1);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        ar[u].pb(v);
        ra[v].pb(u);
    }
    for (int i = 1; i <= n; i++) {
        if (vi[i]) continue;
        topsort(i);
    }
    vi.assign(n+1, false);
    while (!ord.empty()) {
        if (!vi[ord.back()]) {
            vector<int> temp;
            dfs(ord.back(), temp);
            ssc.pb(temp);
        }
        ord.pop_back();
    }
    cout << scc.size() << endl;
}