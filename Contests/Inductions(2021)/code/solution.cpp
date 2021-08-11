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

void dfs(vector <int>& ans, vector <int> ar[], vector <bool>& vi, int s) {
    vi[s] = true;
    for(auto it: ar[s]) {
        if(vi[it]) continue;
        dfs(ans, ar, vi, it);
    }
    ans.push_back(s);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector <int> ar[n+1], ans;
    vector <bool> vi(n+1);
    vector <lli> dp(n+1, 0);
    dp[1] = 1;
    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        ar[u].pb(v);
    }
    dfs(ans, ar, vi, 1);
    reverse(ans.begin(), ans.end());
    for(auto it: ans) {
        for(auto ti : ar[it]) {
            dp[ti] = (dp[ti] + dp[it]) % mod;
        }
    }
    cout << dp[n] << endl;
}