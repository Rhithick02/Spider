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
#define SIZE 10
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

vector <pair<int, int>> edge[SIZE];
vector <pair <int, pair<int, int>>> store, result;
vector <int> parent(SIZE), size(SIZE);

void make_set(int node) {
    parent[node] = node;
    size[node] = 1;
}
int find_set(int node) {
    if(node == parent[node]) {
        return node;
    }
    return parent[node] = find_set(parent[node]);
}
void union_set(int node1, int node2) {
    int a = find_set(node1);
    int b = find_set(node2);
    if(a != b) {
        if(size[a] < size[b]) {
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

int main(){
    ios::sync_with_stdio(false);
    int n, m, u, v, w, cost = 0;
    cin >> n >> m;
    For(i, 0, m) {
        cin >> u >> v >> w;
        edge[u].pb({v, w});
        edge[v].pb({u, w});
        store.pb({w, {u, v}});
    }
    sort(asc(store));
    For(i, 1, n+1) {
        make_set(i);
    }
    for(auto to: store) {
        if(parent[to.se.fi] != parent[to.se.se]) {
            cost += to.fi;
            result.pb(to);
        }
        union_set(to.se.fi, to.se.se);
    }
    cout << cost << endl;
}