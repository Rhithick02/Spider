/*Given a value V, if we want to make change for V cents, and we have 
infinite supply of each of C = { C1, C2, .. , Cm} valued coins, what 
is the minimum number of coins to make the change? If it’s not possible 
to make change, print -1. */
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define lli long long
#define For(i,a,n) for(int i=(a);i<n;i++)
#define asc(x) x.begin(),x.end()
#define des(x) x.rbegin(),x.rend()
#define pb push_back
#define fi first
#define se second
#define mod 1000000007
#define MAX 100001
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

int main() {
    int n, sum, x = mod;
    cin >> n >> sum;
    vector <int> ar(n), dp(sum + 1, mod);
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = ar[i]; j <= sum; j++) {
            dp[j] = min(dp[j], 1 + dp[j-ar[i]]);
        }
    }
    // for(int i = 1; i <= sum; i++) cout << dp[i] << " ";
    cout << (dp[sum] != mod ? dp[sum] : -1) << endl;
}