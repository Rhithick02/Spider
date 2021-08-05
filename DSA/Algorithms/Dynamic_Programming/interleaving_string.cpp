/*Given three strings A, B and C. Write a function that checks whether C 
is an interleaving of A and B. C is said to be interleaving A and B, if 
it contains all and only characters of A and B and order of all characters 
in individual strings is preserved. */
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
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int n = s1.length(), m = s2.length();
    if(n + m != s3.length()) {
        cout << "0\n";
    } else {
        vector <vector <bool>> dp(n+1, vector <bool>(m+1, 0));
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(!i && !j) {
                    dp[i][j] = true;
                } else if(!i) {
                    dp[i][j] = dp[i][j-1] && (s3[i+j-1] == s2[j-1]);
                } else if(!j) {
                    dp[i][j] = dp[i-1][j] && (s3[i+j-1] == s1[i-1]);
                } else {
                    dp[i][j] = (dp[i][j-1] && (s3[i+j-1] == s2[j-1])) || (dp[i-1][j] && (s3[i+j-1] == s1[i-1]));
                }
            }
        }
        cout << dp[n][m] << endl;
    }
}