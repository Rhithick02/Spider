/* There are n people who want to get to the top of a building which has only one elevator. You know the weight of each person and the maximum allowed weight in the elevator. What is the minimum number of elevator rides? */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define lli long long
#define fi first
#define se second
#define mod 1000000007
#define MAX 100001
#define pb push_back
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

int main() {
    int n, x;
    cin >> n >> x;
    vector <int> ar(n);
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    vector <pair<int, int>> dp(1 << n);
    dp[0] = {1, 0};
    for(int i = 1; i < (1 << n); i++) {
        dp[i] = {n+1, 0};
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                pair <int, int> temp = dp[i ^ (1 << j)];
                if(temp.se + ar[j] <= x) {
                    temp.se += ar[j];
                } else {
                    temp.se = ar[j];
                    temp.fi++;
                }
                dp[i] = min(dp[i], temp);
            }
        }
    }
    cout << dp[(1 << n) - 1].fi << endl;
}