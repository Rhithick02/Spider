// One indexed BIT
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define lli long long
#define fi first
#define se second
#define mod 1000000007
#define MAX 100001
#define pb push_back
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

vector <int> bit;
int sum(int i) {
    int ans = 0;
    i++;
    while(i >= 1) {
        ans += bit[i];
        i -= i & (-i);
    }
    return ans;
}
int range_sum(int l, int r) {
    return sum(r) - sum(l-1);
}
void update(int idx, int x, int n) {
    for(++idx; idx <= n; idx += idx & (-idx)) {
        bit[idx] += x;
    }
}
void build_tree(const vector <int>& ar) {
    int n = ar.size();
    for(int i = 0; i < n; i++) {
        update(i, ar[i], n);
        for(int i = 1; i <= n; i++) {
            cout << bit[i] << " ";
        }
        cout << endl;
    }
}
int main() {
    int n;
    cin >> n;
    vector <int> ar(n);
    bit.assign(n+1, 0);
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    build_tree(ar);
    update(2, 5, n);
    // l, r is 0-indexed only bit is 1 indexed
    cout << range_sum(1, 4) << endl;
}