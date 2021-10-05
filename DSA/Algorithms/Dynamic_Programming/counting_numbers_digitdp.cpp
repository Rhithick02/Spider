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

lli dp[20][10][2][2];
lli solve(string& num, int n, int lDigit, bool lead_zero, bool tight) {
    if(n == 0) {
        return 1;
    }
    if(lDigit != -1 && dp[n][lDigit][lead_zero][tight] != -1) {
        return dp[n][lDigit][lead_zero][tight];
    }
    int ub = (tight ? num[num.length() - n] - '0': 9);
    lli ans = 0;
    for(int j = 0; j <= ub; j++) {
        if(j == lDigit && lead_zero == 0) {
            continue;
        }
        ans += solve(num, n-1, j, lead_zero & (j == 0), tight & (j == ub)); 
    }
    return dp[n][lDigit][lead_zero][tight] = ans;
}

int main() {
    lli a, b;
    cin >> a >> b;
    string A, B;
    A = to_string(a-1), B = to_string(b);
    memset(dp, -1, sizeof(dp));
    lli t1 = solve(B, B.length(), -1, true, true);
    memset(dp, -1, sizeof(dp));
    lli t2 = solve(A, A.length(), -1, true, true);
    cout << t1 - t2 << endl;
}