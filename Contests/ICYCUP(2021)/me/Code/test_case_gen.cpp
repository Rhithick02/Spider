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
#define val 10000
#define lim_n 100
#define lim_t 5
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

int main() {
    srand(time(0));
    int t = rand() % (lim_t-1) + 2;
    int count = 0;
    cout << t << "\n";
    for(int i = 1; i <= t; i++) {
        int n = rand() % (lim_n-1) + 2;
        while(lim_n - (count + n) < 2 * (t - i) || n > lim_n * 0.2) {
            n = rand() % 200 + 2;
        }
        count += n;
        cout << n << "\n";
        for(int j = 1; j <= n; j++) {
            cout << rand() % val + 1 << " ";
        }
        cout << "\n";
    }
}