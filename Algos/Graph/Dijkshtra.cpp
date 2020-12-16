#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define For(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vil vector<long long>
#define asc(x) x.begin(),x.end()
#define des(x) x.rbegin(),x.rend()
#define pb push_back
#define fi first
#define se second

void bfs(vector< pair<int,int> >ar[],int start,int tot,int connect) {
    multiset <pair<int, int>> te;// priority_queue< pair<int,int>,vector< pair<int,int> >,greater< pair<int,int> > > te;
    vil ans(tot);
    for(int i = 1; i < tot; i++) ans[i] = 1e9;
    te.insert({0, start});
    int count=0;
    while(count < connect) {
        pair<int,int> pa = *te.begin();
        te.erase(te.begin());
        if(ans[pa.se] != 1e9) continue;
        ans[pa.se] = pa.fi;
        for(auto it: ar[pa.se])
            te.insert({pa.fi + it.se, it.fi});
        count++;
    }
    for(int i = 2; i < tot; i++) cout<<ans[i]<<" ";
}
int main(){
    int n,m,u,v,w;
    set<int> st;
    cin >> n >> m;
    vector< pair<int,int> > ar[n+1];
    For(i,m) {
        cin>>u>>v>>w;
        st.insert(u);
        st.insert(v);
        ar[u].pb({v,w});
    }
    bfs(ar,1,n+1,st.size());
    return 0;
}