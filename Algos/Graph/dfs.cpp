#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> ar[],int u,int v)
{
    ar[u].push_back(v);
    ar[v].push_back(u);
}
void dfs2(vector<int> ar[],int startvertex,int totvertex,bool visited[])
{
    visited[startvertex]=true;
    cout<<startvertex<<" ";
    vector<int>::iterator it;
    for(it=ar[startvertex].begin();it!=ar[startvertex].end();it++)
    {
        if(!visited[*it])
            dfs2(ar,*it,totvertex,visited);
    }
}
void dfs(vector<int> ar[],int startvertex,int totvertex)
{
    bool visited[totvertex]={false};
    dfs2(ar,startvertex,totvertex,visited);
}
int main()
{
    int V=5,count=0;
    vector<int> ar[V];
    addEdge(ar,0,1);
    addEdge(ar,0,4); 
    addEdge(ar,1,2); 
    addEdge(ar,1,3); 
    addEdge(ar,1,4); 
    addEdge(ar,2,3); 
    addEdge(ar,3,4);
    dfs(ar,0,5);
    return 0;
}