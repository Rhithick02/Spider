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
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

struct stacks {
    int data;
    stacks* next;
};

stacks* top = NULL;

stacks* newnode(int val) {
    stacks* temp = new stacks();
    temp -> data = val;
    temp -> next = NULL;
    return temp;
}

bool isempty() {
    if(top == NULL) {
        return true;
    }
    return false;
}

void push(int val) {
    stacks* temp = newnode(val);
    temp -> next = top;
    top = temp;
}

int pop() {
    if(top == NULL) {
        return -1;
    }
    int temp = top -> data;
    top = top -> next;
    return temp;
}

int stacktop() {
    return top -> data;
}

int main(){
    ios::sync_with_stdio(false);
    push(5);
    push(1);
    cout << stacktop() << endl;
    pop();
    cout << stacktop() << endl;
}