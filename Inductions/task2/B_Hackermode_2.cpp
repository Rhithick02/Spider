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

int main(){
    ios::sync_with_stdio(false);
    // Hacker mode 2
    // Coordinate compression method
    lli n, q, l, r, val, sum = 0, maxi = 0;
    cin >> n >> q;
    vector <lli> ar, res(2 * 100001);
    vector <pair<pair<lli, lli>, lli>> te;
    For(i, 0, q) {
        cin >> l >> r >> val;
        te.pb({{l, r}, val});
        ar.pb(l), ar.pb(r + 1); // Adding indices l and r to new array
    }
    sort(asc(ar));
    ar.pb(n);
    ar.resize(unique(asc(ar)) - ar.begin()); // Sorting and removing duplicate elements
    for(auto it: te) {
        l = lower_bound(asc(ar), it.fi.fi) - ar.begin(); // Finding the relative position of indices
        r = lower_bound(asc(ar), it.fi.se + 1) - ar.begin();
        res[l] += it.se, res[r] -= it.se;
    }
    For(i, 0, ar.size()) {
        /* Ex: If we have array
        ar: 1 4 5 8 9 10
        res:10 -10 15 5 -15 -5
        the value at 1st index is 10 + 1 and at 3rd index it is 10 + 3
        whereas value at index 4 is 10 - 10 + 4 */               
        maxi = max(maxi,  sum + ar[i] - 1);
        sum += res[i];
        maxi = max(maxi,  sum + ar[i]);
    }
    cout << maxi << endl;
}