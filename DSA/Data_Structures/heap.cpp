/* Building a mzx heap. 
    1 -> Down_heapify
    2 -> Up_heapfiy
    3 -> Insertion
    4 -> Deletion
    5 -> Get_max
    6 -> Extract max    */
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

void down_heapify(vector <int>& ar, int node, int n) {
    int left_child = 2 * node + 1;
    int right_child = left_child + 1;
    int largest = node;
    if(left_child < n && ar[largest] < ar[left_child]) {
        largest = left_child;
    }
    if(right_child < n && ar[largest] < ar[right_child]) {
        largest = right_child;
    }
    if(largest != node) {
        swap(ar[largest], ar[node]);
        down_heapify(ar, largest, n);
    }
}
void up_heapify(vector <int>& ar, int node) {
    int parent = (node - 1) / 2;
    if(ar[parent] < ar[node]) {
        swap(ar[parent], ar[node]);
        up_heapify(ar, parent);
    }
}
void insert(vector <int>& ar, int value) {
    ar.push_back(value);
    int n = ar.size();
    up_heapify(ar, n-1);
}
void remove(vector <int>& ar, int index) {
    int n = ar.size();
    swap(ar[index], ar[n-1]);
    ar.pop_back();
    down_heapify(ar, index, n-1);
}
int get_max(vector <int>& ar) {
    return ar[0];
}
int extract_max(vector <int>& ar) {
    int n = ar.size(), max_ = ar[0];
    swap(ar[0], ar[n-1]);
    ar.pop_back();
    down_heapify(ar, 0, n - 1);
    return max_;
}
int main() {
    int n;
    cin >> n;
    vector <int> ar(n);
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    // Building the heap
    for(int i = n / 2 - 1; i >= 0; i--) {
        down_heapify(ar, i, n);
    }
    cout << "Maximum element in the heap: " << extract_max(ar) << endl;
    insert(ar, 100);
    cout << "Maximum element in the heap: " << get_max(ar) << endl;
    remove(ar, 0);
    cout << "Maximum element in the heap: " << get_max(ar) << endl;
}