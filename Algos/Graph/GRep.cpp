//Graph Representation using adjacency list
#include<bits/stdc++.h>
using namespace std;
void addedge(vector<int> ar[],int u,int v)
{
    ar[u].push_back(v);
    ar[v].push_back(u);
}
void printgraph(vector<int> ar[],int V)
{
    vector<int>::iterator it;
    for(int i=0;i<V;i++)
    {
        cout<<i<<"-----> ";
        for(it=ar[i].begin();it!=ar[i].end();it++)
            cout<<*it<<" ";
        cout<<endl;
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
    printgraph(ar,V);
    return 0;
}