/*Given a value N, if we want to make change for N cents, and we have infinite supply of each of 
S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? 
The order of coins doesn’t matter.*/

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
    int n, sum;
    cin >> n >> sum;
    vector <int> ar(n), dp(sum+1);
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = ar[i]; j <= sum; j++) {
            dp[j] += dp[j - ar[i]];
        }
    }
    cout << dp[sum] << endl;
}