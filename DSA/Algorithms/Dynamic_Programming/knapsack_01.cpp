/*Given weights and values of n items, put these items in a knapsack
of capacity W to get the maximum total value in the knapsack. */
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
    int n, w;
    cin >> n >> w;
    vector <int> weights(n), values(n);
    for(int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> values[i];
    }
    vector <vector <int>> dp(n+1, vector <int>(w+1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= w; j++) {
            dp[i][j] = max(dp[i-1][j], (j-weights[i-1] >= 0 ? dp[i-1][j-weights[i-1]] + values[i-1] : 0));
        }
    }
    cout << dp[n][w] << endl;
}