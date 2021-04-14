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

void radix_sort(vector <int> &ar, int n) {
    int maxi = *max_element(asc(ar));
    vector <int> output(n);
    for(int i = 1; maxi / i > 0; i *= 10) {
        vector <int> cnt(10);
        for(int j = 0; j < n; j++) {
            cnt[(ar[j] / i) % 10]++;
        }
        for(int j = 1; j < 10; j++) {
            cnt[j] += cnt[j-1];
        }
        for(int  j = 0; j < n; j++) {
            output[--cnt[(ar[j] / i) % 10]] = ar[j];
        }
        ar = output;
    }
}

int main() {
    int n;
    cin >> n;
    vector <int> ar(n);
    for(auto &it: ar) cin >> it;
    radix_sort(ar, n);
    for(auto it: ar) cout << it << " ";
}