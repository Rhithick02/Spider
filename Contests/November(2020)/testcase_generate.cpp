#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
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
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

int main(){
    ios::sync_with_stdio(false);
    srand((unsigned)time(0));
    int n = rand()%50 + 1, r[2], c[2];
    r[0] = rand()%n + 1;
    c[0] = rand()%n + 1;
    r[1] = rand()%n + 1;
    c[1] = rand()%n + 1;
    vector <string> s;
    For(i, 0, n) {
        string te = "";
        For(j, 0, n) te += '0' + (rand()%2);
        s.pb(te);
    }
    s[r[0]-1][c[0]-1] = s[r[1]-1][c[1]-1] = '0';
    cout << n << "\n";
    For(i, 0, 2)
        cout << r[i] << " " << c[i] << "\n";
    For(i, 0, n) 
        cout << s[i] << "\n";
}