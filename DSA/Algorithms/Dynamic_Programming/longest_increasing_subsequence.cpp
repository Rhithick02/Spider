/* find the length of the longest subsequence of a given sequence such that all elements of the 
subsequence are sorted in increasing order.*/

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
    int n;
    cin >> n;
    vector <int> ar(n), lis(n, 1);
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(lis[i] <= lis[j] && ar[i] > ar[j]) {
                lis[i] = lis[j] + 1;
            }
        }
    }
    cout << *max_element(lis.begin(), lis.end()) << endl;
}