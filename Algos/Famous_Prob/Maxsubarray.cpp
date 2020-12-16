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
int n, x;
vector <int> ar;
int max_cross(int l, int mid, int r) {
    int sum = 0, lans = -1e9, rans = 0;
    for(int i = mid; i >= l; i--) {
        sum += ar[i];
        if(sum > lans) lans = sum;
    }
    sum = 0;
    for(int i = mid + 1; i <= r; i++) {
        sum += ar[i];
        if(sum > rans) rans = sum;
    }
    return max(lans + rans, max(lans, rans));
}
int max_sub(int l, int r) {
    if(l == r) return ar[l];
    int mid = l + r >> 1;
    return max(max_sub(l, mid), max(max_sub(mid + 1, r), max_cross(l, mid, r)));
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    For(i, 0, n) {
        cin >> x;
        ar.pb(x);
    }
    cout << max_sub(0, n - 1) << "\n";
}