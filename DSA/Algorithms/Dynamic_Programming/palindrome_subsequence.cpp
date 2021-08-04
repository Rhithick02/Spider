// Find the longest palindromic subsequence
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
    string s;
    cin >> s;
    int n = s.length();
    vector <vector <int>> dp(n, vector <int> (n, 0));
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    for(int len = 2; len <= n; len++) {
        for(int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            if(s[i] == s[j]) {
                if(len == 2) dp[i][j] = 2;
                else {
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[0][n-1] << endl;
}