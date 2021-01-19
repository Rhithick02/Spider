#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
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

class bit {
    int add[2];
    vector <int> tree;
    public:
    bit(vector <int> ar) {
        add[0] = add[1] = 0;
        int n = ar.size();
        tree.pb(0);
        For(i, 1, n+1) {
            int te = i & -i;
            For(j, i-te+1, i+1) tree[i] += ar[j-1];
        }
    }
    int upd(int, int);
    void sum(int, int);
};

int bit :: sum(int l, int r) {
    l--;
    add[0] = 0;
    add[1] = 0;
    while(l >= 1) {
        add[0] += tree[l];
        l -= l & -l;
    }
    while(r >= 1) {
        add[1] += tree[r];
        r -= r & -r;
    }
    return add[1] - add[0];
}

void bit :: upd(int k, int val) {
    while(k <= n) {
        tree[k] += val;
        k += k & -k;
    }
}

int main(){
    ios::sync_with_stdio(false);
    int n, q, l, r;
    cin >> n >> q;
    vector <int> ar(n);
    For(i, 0, n) cin >> ar[i];
    bit x(ar);
    For(i, 0, q) {
        cin >> l >> r;
        cout << x.sum(l, r) << endl;
    }
}