// Sum of area of all rectangles formed by lines parallel to x axis and y axis
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
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main(){
    ios::sync_with_stdio(false);
    lli n, m, sum[2] = {0,0};
    cin >> n >> m;
    vector <lli> r(m), c(n);
    For(i, 0, n) cin >> c[i];
    For(i, 0, m) cin >> r[i];
    sort(asc(r)), sort(asc(c));
    For(i, 0, m) sum[0] = (sum[0] + 1LL * i * r[i] + mod) % mod;
    For(i, 0, m) sum[0] = (sum[0] - 1LL * (m-i-1) * r[i] + mod) % mod;
    For(i, 0, n) sum[1] = (sum[1] + 1LL * i * c[i] + mod) % mod;
    For(i, 0, n) sum[1] = (sum[1] - 1LL * (n-i-1) * c[i] + mod) % mod;
    sum[0] = ((n * (n-1)) % mod * sum[0]) % mod;
    sum[1] = ((m * (m-1)) % mod * sum[1]) % mod;
    cout << (sum[0] + sum[1]) % mod << "\n";
}