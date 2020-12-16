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
    // LIS in O(n ^ 2)
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <int> ar(n), lis(n, 1);
    For(i, 0, n) cin >> ar[i];
    For(i, 1, n) {
        For(j, 0, i) {
            if(ar[i] > ar[j]) 
                lis[i] = max(lis[i], lis[j] + 1);
        }
    }
    for(auto it: lis) cout << it << " ";
    cout << endl;
}