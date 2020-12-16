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
    int n, max_cap;
    cin >> n >> max_cap;
    vector <int> weight(n), profit(n);
    int dp[n+1][max_cap+1];
    memset(dp, 0, sizeof(dp));
    For(i, 0, n) cin >> weight[i];
    For(i, 0, n) cin >> profit[i];
    For(i, 1, n + 1) {
        For(j, 1, max_cap + 1) {
            if(weight[i-1] > j || j - weight[i-1] < 0)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], profit[i-1] + dp[i-1][j-weight[i-1]]);
        }
    }
    cout << dp[n][max_cap] << endl;
}