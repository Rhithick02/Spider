#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> ar;
    ar.push_back(1);
    ar.push_back(2);
    ar.push_back(3);
    ar.push_back(4);
    ar.erase(ar.begin()+1);
    cout<<ar[1];
    return 0;
}