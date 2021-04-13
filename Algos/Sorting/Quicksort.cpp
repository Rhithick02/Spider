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

int partition(vector <int> &ar, int p, int r) {
    int x = ar[r];
    int i = p - 1;
    for(int j = p; j < r; j++) {
        if(ar[j] < x) {
            swap(ar[++i], ar[j]);
        }
    }
    swap(ar[++i], ar[r]);
    return i;
}

void quick_sort(vector <int> &ar, int p, int r) {
    if(p >= r) {
        return;
    }
    int q = partition(ar, p, r);
    quick_sort(ar, p, q-1);
    quick_sort(ar, q+1, r);
}
int main() {
    int n;
    cin >> n;
    vector <int> ar(n);
    for(auto &it: ar) cin >> it;
    quick_sort(ar, 0, n-1);
    for(auto it: ar) cout << it << " ";
}