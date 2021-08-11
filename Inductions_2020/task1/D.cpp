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
    int n, r, x, y, te, change = 0;
    cin >> n >> r >> x >> y;
    vector <int> c(n);
    For(i, 0, n) cin >> c[i];
    For(i, 0, n) {
        cin >> te;
        if(!c[i]) continue; // The days without contest doesnt matter
        change += (te ? x:-y); // Adding x if he eats chicken or subracting y if he doesn't
    }
    if(change > 0) cout << "promoted\n";
    else if(change < 0) cout << "demoted\n";
    else cout << "no change\n";
}