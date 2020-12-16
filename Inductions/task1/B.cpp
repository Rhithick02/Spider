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
    int n, cnt = 0;
    string s;
    cin >> n >> s;
    while(n > 1) {
        int fl = 0;
        // Checking the length of string by comparing 1st half of the string to the next half
        For(i, 0, n/2) {
            if(s[i] != s[n/2 + i]) {
                fl = 1;
                break;
            }
        }
        if(fl) break; // If a char from a distance x from start is not equal to x + half length of the string loop breaks
        cnt++;
        n /= 2;
    }
    cout << cnt << "\n";
}