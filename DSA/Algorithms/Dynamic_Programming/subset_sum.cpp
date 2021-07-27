/* Given a set of non-negative integers, and a value sum, determine if there is a 
subset of the given set with sum equal to given sum and print the subsets */

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

void subsets(vector <int> &ar, int sum, int n, vector <vector <bool>> &dp, vector <int> &ans) {
    if(n == 0 && sum == 0) {
        for(auto it: ans) cout << it << " ";
        cout << "\n";
        return;
    }
    if(dp[sum][n-1]) {
        vector <int> b = ans;
        subsets(ar, sum, n-1, dp, ans);
    }
    if(sum >= ar[n-1] && dp[sum-ar[n-1]][n-1]) {
        ans.push_back(n-1);
        subsets(ar, sum - ar[n-1], n-1, dp, ans);
    }
    if(!(dp[sum][n-1]))
        ans.pop_back();
}
int main() {
    int n, sum;
    cin >> n >> sum;
    vector <vector <bool>> dp(sum+1, vector <bool> (n+1, false));
    vector <int> res, ar(n);
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
        dp[0][i] = true;
    }
    for(int j = 1; j <= n; j++) {
        for(int i = 1; i <= sum; i++) {
            dp[i][j] = (dp[i][j-1] || (i - ar[j-1] >= 0 ? dp[i-ar[j-1]][j-1] : false));
        }
    }
    cout << dp[sum][n] << endl;
    subsets(ar, sum, n, dp, res);
}