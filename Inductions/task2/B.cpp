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
    // Hacker mode 1:
    ios::sync_with_stdio(false);
    int n, q, l, r, val;
    cin >> n >> q;
    vector <lli> pref(n + 2);
    For(i, 0, q) {
        cin >> l >> r >> val;
        pref[l] += val;     // Adding val to the start of index
        pref[r+1] -= val;   // Subtracting val from end of then range 
    }
    For(i, 1, n + 1) pref[i] += pref[i-1];  // Calculating overall prefix
    For(i, 1, n + 1) pref[i] += i;  // Adding the initial value(index) to the array
    cout << *max_element(asc(pref)) << endl;
}
