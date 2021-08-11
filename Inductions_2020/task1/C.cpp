#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define For(i,a,n) for(int i=(a);i<n;i++)
#define asc(x) x.begin(),x.end()
#define des(x) x.rbegin(),x.rend()
#define pb push_back
#define fi first
#define se second
int ar[] = {7, 8, 9, 10, 16, 43};
vector <int> res, te;
void fuct(int val) {
    For(i, 0, 6) {
        For(j, i+1, 6) {
            if(ar[i] * ar[j] == val)
                te.pb(i), te.pb(j);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    int x[4], first;
    cout << "1 2\n" << flush;
    cin >> x[0]; // Finding which 2 elements product is x[1]
    fuct(x[0]);
    cout << "1 3\n" << flush;
    cin >> x[1];
    fuct(x[1]); // Finding which 2 elements product is x[1] 
    if(te[0] == te[2] || te[0] == te[3]) // Finding the pivot i.e, the first element
        first = ar[te[0]];
    else 
        first = ar[te[1]];
    cout << "1 4\n" << flush;
    cin >> x[2];
    cout << "1 5\n" << flush;
    cin >> x[3];
    res.pb(first);
    For(i, 0, 4) res.pb(x[i]/first);
    For(i, 0, 6){  
        int fl = 0; // Finding the last element
        For(j, 0, 5){
            if(ar[i] == res[j]) fl = 1;
        }
        if(!fl) res.pb(ar[i]);
    }
    for(auto it: res) cout << it << " ";
}