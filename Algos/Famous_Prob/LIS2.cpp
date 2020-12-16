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
#define MAX 1e9
int main(){
    ios::sync_with_stdio(false);
    int n, len = 1;
    cin >> n;
    vector <int> ar(n), lis(n + 1, MAX);
    lis[0] = -1e9;
    For(i, 0, n) {
        cin >> ar[i];
        int pos = upper_bound(asc(lis), ar[i]) - lis.begin();
        if(lis[pos-1] < ar[i]) {
            lis[pos] = ar[i];
            len = max(len, pos);
        }
    }
    cout << len << endl;
    for(auto it: lis) cout << it << " ";
}