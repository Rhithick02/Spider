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
#define MAX 100001
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

void max_heapify(vector <int> &ar, int i, int siz) {
    int large = i;
    int left = i * 2 + 1;
    int right = left + 1;
    if(left < siz && ar[left] > ar[large]) {
        large = left;
    }
    if(right < siz && ar[right] > ar[large]) {
        large = right;
    }
    if(large != i) {
        swap(ar[large], ar[i]);
        max_heapify(ar, large, siz);
    }
}
void increase_key(vector <int> &ar, int i, int key) {
    ar[i] = key;
    while(i >= 0 && ar[i/2-1] < ar[i]) {
        swap(ar[i/2-1] , ar[i]);
        i = i/2-1;
    }
}
void heap_increase(vector <int> &ar, int key) {
    ar.pb(-mod);
    increase_key(ar, ar.size()-1, key);
}
int heap_erase_max(vector <int> &ar) {
    int max = ar[0];
    swap(ar[0], ar.back());
    ar.pop_back();
    max_heapify(ar, 0, ar.size()-1);
    return max;
}
void heap_sort(vector <int> ar) {
    /* Sorting by taking the first nummber and swapping with last number and
       reducing the size of heap by one */
    for(int i = ar.size() - 1; i > 0; i--) {
        swap(ar[i], ar[0]);
        max_heapify(ar, 0, i);
    }
    for(auto it: ar) cout << it << " ";
}
int main() {
    int n;
    cin >> n;
    vector <int> ar(n);
    for(auto & it: ar) cin >> it;
    for(int i = n/2-1; i >= 0; i--) {
        max_heapify(ar, i, n);
    }
    heap_increase(ar, 6);
}