/* Find total no of strongly connected components in a graph */
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

void top_sort(vector <int>& ans, vector <int> ar[], vector <bool>& vi, int s) {
    vi[s] = true;
    for(auto it: ar[s]) {
        if(vi[it]) continue;
        top_sort(ans, ar, vi, it);
    }
    ans.push_back(s);
}
void reverse(vector <int> rev[], vector <int> ar[], int n) {
    for(int i = 1; i <= n; i++) {
        for(auto it: ar[i]) {
            rev[it].push_back(i);
        }
    }
}
void dfs(vector <int> rev[], vector <bool>& vi, int s) {
    vi[s] = true;
    for(auto it: ar[s]) {
        if(vi[it]) continue;
        dfs(rev, vi, it);
    }
}
int main() {
    int n, m, cnt = 0;
    cin >> n >> m;
    vector <int> ar[n+1], rev[n+1], ans;
    vector <bool> vi(n+1);
    for(int i = 0, u, v; i < n; i++) {
        cin >> u >> v;
        ar[u].push_back(v);
    }
    // Finding the topological order to get the source node
    for(int i = 1; i <= n; i++) {
        if(vi[i]) continue;
        top_sort(ans, ar, vi, i);
    }

    // Reversing the graph
    reverse(rev, ar, n);

    // Reusing the visited array
    for(int i = 1; i <= n; i++) {
        vi[i] = false;
    }

    while(!ans.empty()) {
        int cur = ans.back();
        ans.pop_back();
        if(vi[cur]) continue;
        dfs(rev, vi, cur);
        cnt++;
    }
    cout << cnt << endl;
}