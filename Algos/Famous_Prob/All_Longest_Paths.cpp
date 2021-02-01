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

vector <int> ed[8], length(8), dist1(8);
void dfs(int s, int p) {
    for(auto it: ed[s]) {
        if(it == p) continue;
        length[it] = length[s] + 1;
        dfs(it, s);
    }
}
void bfs(int s) {
    queue <int> q;
    vector <bool> v(8);
    vector <int> lvl(8);
    q.push(s);
    v[s] = true;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto it: ed[cur]) {
            if(v[it]) continue;
            v[it] = true;
            lvl[it] = lvl[cur] + 1;
            dist1[it] = max(dist1[it], lvl[it]);
            q.push(it);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    int u, v;
    For(i, 1, 7) {
        cin >> u >> v;
        ed[u].pb(v);
        ed[v].pb(u);
    }
    dfs(1, 0);
    int node1 = max_element(asc(length)) - length.begin();
    For(i, 1, 8) length[i] = 0;
    dfs(node1, 0);
    int node2 = max_element(asc(length)) - length.begin();
    bfs(node1);
    bfs(node2);
    For(i, 1, 8) cout << dist1[i] << " ";
}