/*Given a rod of length n inches and an array of prices 
that includes prices of all pieces of size smaller than n. 
Determine the maximum value obtainable by cutting up the 
rod and selling the pieces. */
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
    int n;
    cin >> n;
    vector <int> ar(n), dp(n);
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
        dp[i] = ar[i];
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            dp[i] = max(dp[i], dp[j] + dp[i-j-1]);
        }
    }
    cout << dp[n-1] << endl;
}