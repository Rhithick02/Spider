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

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}
int find_set(int a) {
    if(parent[a] == a) {
        return a;
    }
    return parent[a] = find_set(parent[a]);
}
void union_set(int a, int b) {
    int parent_a = find_set(a);
    int parent_b = find_set(b);
    if(parent_a == parent_b) {
        return;
    }
    if(size[a] < size[b]) {
        swap(a, b);
    }
    parent[b] = a;
    size[a] += size[b];
}
int main() {
    int n, m;
    cin >> n >> m;
    vector <pair <int, int>> edge(m);
    vector <int> parent(n+1), size(n+1);
    for(int i = 0; i < m; i++) {
        cin >> edge[i].fi >> edge[i].se;
        union_set(edge[i].fi, edge[i].se);
    }
}