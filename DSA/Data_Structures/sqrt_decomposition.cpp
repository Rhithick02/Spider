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

int len, tot_blk;
vector <int> st;
void update(vector <int>& ar, int idx, int delta) {
    int bl = idx / len;
    ar[idx] += delta;
    st[bl] += delta;
}
int find_sum(vector <int>& ar, int l, int r) {
    int st_blk = l / len, end_blk = r / len, sum = 0;
    for(int i = l; i < min(r, len * (st_blk + 1)); i++) {
        sum += ar[i];
    }
    for(int i = st_blk + 1; i < end_blk; i++) {
        sum += st[i];
    }
    for(int i = len * end_blk; i <= r; i++) {
        sum += ar[i];
    }
    return sum;
}
void build_tree(vector <int>& ar) {
    int n = ar.size();
    for(int i = 0; i < n; i++) {
        st[i/len] += ar[i];
    }
}
int main() {
    int n;
    cin >> n;
    len = (int)sqrt(n);
    tot_blk = (n+len-1) / len;
    vector <int> ar(n);
    st.assign(tot_blk, 0);
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    build_tree(ar);
    cout << find_sum(ar, 0, 4) << endl;
    update(ar, 3, -2);
    cout << find_sum(ar, 0, 4) << endl;
}