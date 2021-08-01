/* Largest subarray with equal 1's and 0's in a binary string */
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
    string s;
    cin >> s;
    int n = s.length(), sum = 0, len = 0, ending_index = -1;
    map <int, int> mp;
    mp[0] = -1;
    for(int i = 0; i < n; i++) {
        sum += (s[i] == '1' ? 1 : -1);
        if(mp.find(sum) != mp.end()) {
            if(i - mp[sum] > len) {
                len = i - mp[sum];
                ending_index = i;
            }
        } else {
            mp[sum] = i;
        }
    }
    cout << "[" << ending_index - len + 1 << ", " << ending_index << "]\n";
}