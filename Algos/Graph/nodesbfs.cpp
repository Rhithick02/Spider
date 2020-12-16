//Count total number of nodes in a specifed level by bfs

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,u,v;
    cin>>n;     //input of total vertex
    vector<int> ar[n];
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;   //input of vertices of an edge
        ar[u].push_back(v);
        ar[v].push_back(u);
    }
    int level,flag=0;
    cin>>level;     //To find the nodes at that level
    bool visited[n]={false};
    int lvl[n]={0};
    queue<int> q;
    q.push(0);
    visited[0]=true;
    while(!q.empty())
    {
        int current=q.front();
        q.pop();
        for(auto i : ar[current])
        {
            if(!visited[i])
            {
                visited[i]=true;
                q.push(i);
                lvl[i]=lvl[current]+1;      //making all nodes of an level equal
                if(lvl[i]==level)
                    flag++;
            }
        }
    }
    cout<<flag<<endl;
    return 0;
}