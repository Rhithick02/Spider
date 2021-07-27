/* Given a binary matrix, find out the maximum size square sub-matrix with all 1s.*/
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
    int n, m, _max = 0;
    cin >> n >> m;
    vector <vector <int>> ar(n, vector <int> (m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> ar[i][j];
        }
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(!ar[i][j]) continue;
            ar[i][j] = 1 + min(ar[i-1][j-1], min(ar[i-1][j], ar[i][j-1]));
            _max = max(_max, ar[i][j]);
        }
    }
    cout << _max << endl;
}