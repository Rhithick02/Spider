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
#define n s.length()
int main(){
    ios::sync_with_stdio(false);
    int res = 0;
    string s;
    cin >> s;
    while(n > 1) {
        int te = 0;
        For(i, 0, n) te += s[i] - '0'; // Finding the sum of digits
        s = to_string(te); // That results into new string
        res++; // Increasing the count by 1
    }
    cout << res << endl;
}