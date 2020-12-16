/*You are Given a Row of N adjacent Tiles. Each Tile has an Integer written on it. You can start walking from any Tile 
and move either towards left or right. You can stop anywhere between your starting Tile and End of Tiles in your chosen Direction
(Both Inclusive). Find the maximum Sum of integers (on Tiles) you collect on the Way. Additionally, You are also given a Lifeline 
which you can use atmost once. Allowing a Jump over atmost K Tiles (not collecting those values).*/
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

int main(){
    ios::sync_with_stdio(false);
    int n, k, cur = 0, res = 0;
    cin >> n >> k;
    vector <int> a(n), st(n), ts(n);
    For(i, 0, n) cin >> a[i];
    For(i, 0, n) {
        if(cur + a[i] < a[i]) {
            cur = a[i];
        } else {
            cur += a[i];
        }
        st[i] = cur;
    }
    cur = 0;
    For(i, 0, n) {
        if(cur + a[n-i-1] < a[n-i-1]) {
            cur = a[n-i-1];
        } else {
            cur += a[n-i-1];
        }
        ts[n-i-1] = cur;
    }
    for(int i=0; i < n; i++) {
        for(int j=i+1; j<min(n, i+k+2); j++) {
            res = max(res, st[i] + ts[j]);
        }
    }
    cout << res << "\n";
}