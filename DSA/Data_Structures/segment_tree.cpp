/* Segment tree to handle sum queries. */
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

int build_tree(vector <int>& res, vector <int>& ar, int idx, int l, int r) {
    if(l == r) {
        res[idx] = ar[l];
        return ar[l];
    }
    int mid = (l + r) / 2;
    res[idx] = build_tree(res, ar, 2 * idx + 1, l, mid) + build_tree(res, ar, 2 * idx + 2, mid+1, r);
    return res[idx];
}
int find_sum(vector <int>& res, int idx, int cur_l, int cur_r, int need_l, int need_r) {
    if(need_l <= cur_l && need_r >= cur_r) {
        return res[idx];
    }
    if(need_l > cur_r || need_r < cur_l) {
        return 0;
    }
    int mid = (cur_l + cur_r) / 2;
    return find_sum(res, 2 * idx + 1, cur_l, mid, need_l, need_r) + find_sum(res, 2 * idx + 2, mid+1, cur_r, need_l, need_r);
}
void update(vector <int>& res, int idx, int l, int r, int pos, int dif) {
    if(pos < l || pos > r) {
        return;
    }
    res[idx] += dif;
    if(l == r) {
        return;
    }
    int mid = (l + r) / 2;
    update(res, 2 * idx + 1, l, mid, pos, dif);
    update(res, 2 * idx + 2, mid + 1, r, pos, dif);
}
int main() {
    int n;
    cin >> n;
    vector <int> ar(n), seg_tree(4 * n);
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    build_tree(seg_tree, ar, 0, 0, n-1);
    for(auto it: seg_tree) cout << it << " ";
    cout << endl;
    cout << find_sum(seg_tree, 0, 0, n-1, 2, 4) << endl;
}