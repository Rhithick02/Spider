#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define For(i,a,n) for(int i=(a);i<n;i++)
#define asc(x) x.begin(),x.end()
#define des(x) x.rbegin(),x.rend()
#define pb push_back
#define fi first
#define se second

struct node {
    int data;
    node *next;
};
node *head;

void insert(int x) {
    node *new_node = new node;
    new_node -> data = x;
    new_node -> next = head;
    head = new_node;
}
void remove(int x) {
    node *temp = head;
    while(temp -> next -> data != x)
        temp = temp -> next;
    temp -> next = temp -> next -> next;
}
void display() {
    node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}
void reverse() {
    node *prev = NULL, *cur = head;
    while(cur != NULL) {
        node* next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}
int main(){
    ios::sync_with_stdio(false);
    For(i, 0, 5) insert(i + 1);
    display();
    cout << endl;
    reverse();
    display();
    cout << endl;
}