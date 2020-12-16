#include<bits/stdc++.h>
using namespace std;
void addedge(vector<int> ar[],int u,int v)
{
    ar[u].push_back(v);
    ar[v].push_back(u);
}
void bfs(vector<int> ar[],int startvertex,int totvertex)
{
    bool visited[totvertex]={false};
    visited[startvertex]=true;
    queue<int> q;
    q.push(startvertex);
    vector<int>::iterator it;
    while(!q.empty())
    {
        int current=q.front();
        cout<<current<<" ";
        q.pop();
        for(auto v : ar[current])
        {
            if(!visited[v])
            {
                visited[v]=true;
                q.push(v);
            }
        }
    }
}
int main()
{
    int V;//No.of.vertices
    V=5;
    vector<int> ar[V];
    // Adding the edges to the list
    addedge(ar,0,1);
    addedge(ar,0,4); 
    addedge(ar,1,2); 
    addedge(ar,1,3); 
    addedge(ar,1,4); 
    addedge(ar,2,3); 
    addedge(ar,3,4);
    bfs(ar,0,5);
    int e1,e2;
    cin>>e1>>e2;
    if(find(ar[e1].begin(),ar[e1].end(),e2)!=ar[e1].end())
        cout<<"Found";
    else 
        cout<<"Not found";
    return 0;
}