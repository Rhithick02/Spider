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

class segment {
    vector <int> t, minmax;
    int n;
    public:
    segment(int size) {
        n = size;
        t.resize(4 * n + 2);
        minmax.resize(4 * n + 2);
    }
    void build(vector <int> &, int, int, int);
    void build_minmax(vector <int> &, int, int, int);
    void update(int, int, int, int, int);
    int get_minmax(int, int, int, int, int);
    lli sum(int, int, int, int, int);
};

void segment :: build(vector <int> &ar, int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = ar[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(ar, 2 * v, tl, tm);
        build(ar, 2 * v + 1, tm + 1, tr);
        t[v] = t[2*v] + t[2*v+1];
    }
}
lli segment :: sum(int v, int tl, int tr, int l, int r) {
    if(l > tr || r < tl) {
        return 0;
    } else if(l <= tl && r >= tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(2*v, tl, tm, l, r) + sum(2*v+1, tm+1, tr, l, r);
}
void segment :: update(int v, int tl, int tr, int pos, int new_val) {
    if(tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if(pos <= tm) {
            update(2*v, tl, tm, pos, new_val);
        } else {
            update(2*v+1, tm+1, tr, pos, new_val);
        }
        t[v] = t[2*v] + t[2*v+1];
    }
}
void segment :: build_minmax(vector <int> &ar, int v, int tl, int tr) {
    if(tl == tr) {
        minmax[v] = ar[tl];
    } else {
        int tm = (tl + tr) / 2;
        build_minmax(ar, 2*v, tl, tm);
        build_minmax(ar, 2*v+1, tm+1, tr);
        minmax[v] = min(minmax[2*v], minmax[2*v+1]);
    }
}
int segment :: get_minmax(int v, int tl, int tr, int l, int r) {
    if(tr < l || tl > r) {
        return mod;
    } else if(tl >= l && tr <= r) {
        return minmax[v];
    }
    int tm = (tl + tr) / 2;
    return min(get_minmax(2*v, tl, tm, l, r), get_minmax(2*v+1, tm+1, tr, l, r));
}
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <int> ar(n);
    For(i, 0, n) cin >> ar[i];
    segment obj(n);
    obj.build(ar, 1, 0, n-1);
    obj.build_minmax(ar, 1, 0, n-1);
    cout << obj.sum(1, 0, n-1, 2, 4) << endl;
    cout << obj.get_minmax(1, 0, n-1, 2, 4) << endl;
}