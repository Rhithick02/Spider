/*Each cart has a unique batch number- n. The criteria for the cart to be good is that at least k prime numbers from 2 to n 
inclusively can be expressed as the sum of three integer numbers: two neighboring prime numbers and 1. 
For example, 43 = 19 + 23 + 1, or 31 = 13 + 17 + 1.*/
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
    int n, k, cnt = 0;
    cin >> n >> k;
    vector <bool> isprime(1001, true);
    vector <int> st;
    For(i, 2, n + 1) {
        if(!isprime[i]) continue;
        for(int j = i*i; j <= n; j += i)
            isprime[j] = false;
    }
    For(i, 2, n+1) {
        if(isprime[i])
            st.pb(i);
    }
    if(st.size() < k) {
        cout << "Bad\n";
    } else {
        int size = st.size();
        For(i, 2, size) {
            For(j, 0, i-1) {
                if(st[i] == 1+st[j]+st[j+1]) {
                    cnt++;
                    break;
                }
            }
        }
        if(cnt >= k)
            cout << "Good\n";
        else
            cout << "Bad\n";
    }
}