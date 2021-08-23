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

vector <int> flat_tree;
void dfs(vector <int> ar[], int s, vector <int>& tin, vector <int>& tout) {
    static int timer = 0;
    tin[s] = timer++;
    flat_tree.pb(s);
    for(auto to: ar[s]) {
        if(tin[to] != -1) continue;
        dfs(ar, to, tin, tout);
    }
    flat_tree.pb(s);
    tout[s] = timer++;
}
int build_tree(vector <int>& seg_tree, vector <int>& val, int idx, int l, int r) {
    if(l == r) {
        seg_tree[idx] = val[flat_tree[l]];
        return seg_tree[idx];
    }
    int mid = (l + r) / 2;
    seg_tree[idx] = build_tree(seg_tree, val, 2*idx+1, l, mid) + build_tree(seg_tree, val, 2*idx+2, mid+1, r);
}
int find_sum(vector <int>& seg_tree, int idx, int cur_l, int cur_r, int need_l, int need_r) {
    if(need_l > cur_r || need_r < cur_l) {
        return 0;
    }
    if(need_l <= cur_l && need_r >= cur_r) {
        return seg_tree[idx];
    }
    int mid = (cur_l + cur_r) / 2;
    return find_sum(seg_tree, 2*idx+1, cur_l, mid, need_l, need_r) + find_sum(seg_tree, 2*idx+2, mid+1, cur_r, need_l, need_r);
}
void update(vector <int>& seg_tree, int idx, int l, int r, int pos, int val) {
    if(pos < l || pos > r) {
        return;
    }
    seg_tree[idx] += val;
    if(l == r) {
        return;
    }
    int mid = (l + r) / 2;
    update(seg_tree, 2*idx+1, l, mid, pos, val);
    update(seg_tree, 2*idx+2, mid+1, r, pos, val);
}
int main() {
    int n;
    cin >> n;
    vector <int> ar[n+1], tin(n+1, -1), tout(n+1, -1), val(n+1, 0);
    for(int i = 1; i <= n; i++) {
        val[i] = i; // Value of ith node;
    }
    for(int i = 0, u, v; i < n-1; i++) {
        cin >> u >> v;
        ar[u].pb(v);
        ar[v].pb(u);
    }
    // Rooted at 1
    dfs(ar, 1, tin, tout);

    // Build segment tree on flat_tree
    vector <int> seg_tree(4 * flat_tree.size());
    build_tree(seg_tree, val, 0, 0, flat_tree.size()-1);

    // Updating an element
    int node = 3;
    val[node] += 5;
    int l = tin[node], r = tout[node];
    update(seg_tree, 0, 0, flat_tree.size()-1, l, 5);
    update(seg_tree, 0, 0, flat_tree.size()-1, r, 5);
    
    // Finding the sum of sub tree rooted at node 1
    int ans = find_sum(seg_tree, 0, 0, flat_tree.size()-1, l, r);
    cout << ans / 2 << endl; // Dividing by 2 as elements are repeated twice in euler tour
}