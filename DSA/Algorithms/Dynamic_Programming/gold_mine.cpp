/*Given a gold mine of n*m dimensions. Each field in this mine contains a positive integer 
which is the amount of gold in tons. Initially the miner is at first column but can be at 
any row. He can move only (right->,right up /,right down\) that is from a given cell, 
the miner can move to the cell diagonally up towards the right or right or diagonally down 
towards the right. Find out maximum amount of gold he can collect. */

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
    int n, m, res = 0;
    cin >> n >> m;
    vector <vector <int>> ar(n, vector <int> (m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> ar[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < m; j++) {
            ar[i][j] += max((i-1 >= 0 ? ar[i-1][j-1] : 0), \
                        max(ar[i][j-1], (i+1 < n ? ar[i+1][j-1] : 0)));
        }
    }
    for(int i = 0; i < m; i++) {
        res = max(res, ar[n-1][i]);
    }
    cout << res << endl;
}