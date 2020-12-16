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
    int t;
    cin >> t;
    while(t--) {
        int cnt = 0, res = 0;
        string s;
        cin >> s;
        For(i, 0, s.length()) {
            if(s[i] == '<') cnt++;
            else cnt--;
            if(cnt < 0) {
                res = i;
                break;  // If '>' is greater than '<' then it wont be a valid prefix
            }
            else if(!cnt) res = i + 1;
        }
        cout << res << "\n";
    }
}