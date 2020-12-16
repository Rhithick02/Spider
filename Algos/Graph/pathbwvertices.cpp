//To count the total number of paths between 2 vertices
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int V=7,u,v,i=0;
    char ch='y';
    vector<int>ar[V],;
    while(i<9)
    {
        cin>>u>>v;
        ar[u].push_back(v);
        i++;
    }
    int s,e,count=0;
    cin>>s>>e;
    //bool visited[v]={false};
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int current=q.front();
        //visited[current]=true;
        q.pop();
        for(auto i: ar[current])
        {
            if(i==e)
                count++;
            else
                q.push(i);
        }
    }
    if(count!=0)
        cout<<count;
    return 0;
}