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
    int t;
    cin >> t;
    while(t--) {
        int n;
        lli ans = -mod, sum = 0;
        cin >> n;
        vector <int> ar(n), dif(n);
        for(auto &it: ar) cin >> it;
        for(int i = 1; i < n; i++) {
            dif[i] = ar[i] - ar[i-1]; 
        }
        for(int i = 1; i < n; i++) {
            if(sum + dif[i] >= dif[i]) {
                sum += dif[i];
            } else {
                sum = dif[i];
            }
            ans = max(ans, sum);
        }
        cout << ans << "\n";
    }
}