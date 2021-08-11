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
    int n, cnt = 1, sum = 0;
    cin >> n;
    vector <int> ar(n + 1);
    for(int i = 2; i <= n; i++) {
        int fl = 0;  // Finding the numbers without any colour that are divisble by i
        for(int j = i; j <= n; j += i) {
            if(ar[j]) continue;  // If the number already has a colour then continue
            ar[j] = cnt;
            fl = 1;
        }
        if(fl) {  // If atleast once a new colour has been assigned with i as divisible
            sum += cnt;
            cnt++;
        }
    }
    cout << sum << endl;
}