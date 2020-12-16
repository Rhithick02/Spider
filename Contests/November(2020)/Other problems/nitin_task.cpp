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
#define MAX 1000001
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

int count(int n) {
    int cnt = 0;
    while(n) {
        cnt++;
        n = n >> 1;
    }
    return cnt;
}

int count_ones(int n) {
    int cnt = 0;
    while(n) {
        if(n & 1) cnt++;
        n = n >> 1;
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(false);
    vector <int> st;
    vector <bool> isprime(MAX, true);
    for(lli i = 2; i < MAX; i++) {
        if(!isprime[i]) continue;
        for(lli j = i * i; j < MAX; j += i)
            isprime[j] = false;
    }
    For(i, 2, MAX) {
        if(isprime[i])
            st.pb(i);
    }
    int t;
    cin >> t;
    while(t--) {
        int n, maxi, cnt = 0, mini = 2e5, res = 0;
        cin >> n;
        cnt = count(n);
        maxi = (1 << cnt) - 1;
        for(auto it: st) {
            if(it > maxi)
                break;
            int te = count_ones(n ^ it);
            if(te <= mini) {
                mini = te;
                res = it;
            }
        }
        cout << res << "\n";
    }
} 