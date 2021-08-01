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

vector <int> solve(vector <int> ar, int n) {
    vector <int> temp, great(n);
    for(int i = 0; i < n; i++) {
        while(temp.size() && ar[temp.back()] > ar[i]) {
            temp.pop_back();
        }
        if(!temp.size()) {
            great[i] = 0;
        } else {
            great[i] = temp.back() + 1;
        }
        temp.push_back(i);
    }
    return great;
}

int main() {
    int n, ans = 0;
    cin >> n;
    vector <int> ar(n), left_great(n), right_great(n);
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    left_great = solve(ar, n);

    reverse(asc(ar));
    right_great = solve(ar, n);
    reverse(asc(right_great));
    reverse(asc(ar));
    for(auto &it: right_great) it = n - 1 - it;

    for(auto it: left_great) cout << it << " ";
    cout << endl;
    for(auto it: right_great) cout << it << " ";
    for(int i = 0; i < n; i++) {
        ans = max(ans, ar[i] * (right_great[i] - left_great[i] + 1));
    } 
    cout << endl;
    cout << ans << endl;
}