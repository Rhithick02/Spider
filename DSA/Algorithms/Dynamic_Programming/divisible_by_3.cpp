/* Given a range L to R from which n numbers are taken. Find the 
number of ways to take n elements such that their sum is divisible by 3. */
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
    int n, l, r;
    cin >> n >> l >> r;
    vector <vector <long long>> dp(n+1, vector <long long> (3, 0));
    vector <long long> store(3);
    // Note r - l >= 2
    store[l%3] = (r - l) / 3 + 1;
    store[(l+1)%3] = (r - l - 1) / 3 + 1;
    store[(l+2)%3] = (r - l - 2) / 3 + 1;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        dp[i][0] = (dp[i-1][0] * store[0] + (dp[i-1][1] * store[2] + dp[i-1][2] * store[1]) % mod) % mod;
        dp[i][1] = (dp[i-1][0] * store[1] + (dp[i-1][1] * store[0] + dp[i-1][2] * store[2]) % mod) % mod;
        dp[i][2] = (dp[i-1][0] * store[2] + (dp[i-1][1] * store[1] + dp[i-1][2] * store[0]) % mod) % mod;
    }
    cout << dp[n][0] << endl;
}