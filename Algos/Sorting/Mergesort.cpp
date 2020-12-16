#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define For(i,a,n) for(int i=(a);i<n;i++)
#define asc(x) x.begin(),x.end()
#define des(x) x.rbegin(),x.rend()
#define pb push_back
#define fi first
#define se second
#define inf 1000000000
int n, x;
vector <int> ar;
void merge(int l, int mid, int r) {
    deque <int> te[2];
    For(i, l, mid + 1) te[0].pb(ar[i]);
    For(i, mid + 1, r + 1) te[1].pb(ar[i]);
    te[1].pb(inf), te[0].pb(inf);
    int k = l;
    while(te[0].size() > 1 || te[1].size() > 1) {
        if(te[0].front() > te[1].front()) {
            ar[k] = te[1].front();
            te[1].pop_front();
        }
        else {
            ar[k] = te[0].front();
            te[0].pop_front();
        }
        k++;
    }
}
void merge_sort(int l, int r) {
    if(l < r) {
        int mid = l + r >> 1;
        merge_sort(l, mid);
        merge_sort(mid + 1, r);
        merge(l, mid, r);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    For(i, 0, n) {
        cin >> x;
        ar.pb(x);
    }
    merge_sort(0, n - 1);
    for(auto it: ar) cout << it << " ";
}