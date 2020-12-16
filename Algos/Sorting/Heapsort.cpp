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
vector <int> ar;
void heapify(int parent, int n) {
    int largest = parent;
    int leftchild = 2 * parent;
    int rightchild = 2 * parent + 1;
    if(leftchild < n && ar[largest] < ar[leftchild])
        largest = leftchild;
    if(rightchild < n && ar[largest] < ar[rightchild])
        largest = rightchild;
    if(largest != parent) {
        swap(ar[largest], ar[parent]);
        heapify(largest, n);
    }
}
int main(){
    ios::sync_with_stdio(false);
    int n, x;
    cin >> n;
    For(i, 0, n) {
        cin >> x;
        ar.pb(x);
    }
    // Building heap
    for(int i = n/2-1; i >= 0; i--)
        heapify(i, n);
    // Removing top element and placing at the end of array
    for(int i = n-1; i > 0; i--) {
        swap(ar[i], ar[0]);
        heapify(0, i);
    }
    for(auto it: ar) cout << it << " ";
}