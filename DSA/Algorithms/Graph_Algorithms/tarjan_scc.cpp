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

void dfs(vector <int> ar[], int s, vector <int>& stack, vector <int>& disc, vector <int>& low, vector <bool>& instack) {
    static int time = 0;
    disc[s] = low[s] = time;
    time++;
    stack.pb(s), instack[s] = true;
    for(auto it: ar[s]) {
        if(disc[it] == -1) {    //If it is not visited
            dfs(ar, it, stack, disc, low, instack);
            low[s] = min(low[s], low[it]);
        } else if(instack[it]) {    //If it is in stack it implies it is a back edge
            low[s] = min(low[s], disc[it]);
        }
        // We will ignore cross edges
    }
    if(low[s] == disc[s]) {
        while(stack.back() != s) {
            cout << stack.back() << " ";
            instack[stack.back()] = false;
            stack.pop_back();
        }
        cout << stack.back() << " ";
        instack[stack.back()] = false;
        stack.pop_back();
    }
}
void tarjan_scc(vector <int> ar[], int n, int m) {
    vector <int> stack, disc(n+1, -1), low(n+1, -1);
    vector <bool> instack(n+1, false);
    for(int i = 1; i <= n; i++) {
        if(disc[i] == -1) {
            dfs(ar, i, stack, disc, low, instack);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector <int> ar[n+1];
    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        ar[u].pb(v);
    }
    tarjan_scc(ar);
}