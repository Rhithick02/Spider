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

struct Node {
    char ch;
    int freq;
    Node *left, *right;
};
struct comp {
    bool operator()(const Node* l, const Node* r) const {
        return l->freq > r->freq;
    }
};
Node* convert(char ch, int freq, Node* left, Node* right) {
    Node *temp = new Node;
    temp -> freq = freq;
    temp -> ch = ch;
    temp -> left = left;
    temp -> right = right;
    return temp;
}
void encode(Node *root, string s, unordered_map<char, string> &mp) {
    if(root == NULL) {
        return;
    }
    if(root -> left == NULL && root -> right == NULL) {
        mp[root -> ch] = (s != "" ? s : "1");
    }
    encode(root -> left, s + "0", mp);
    encode(root -> right, s + "1", mp);
}
int main() {
    string s = "aaaaa";
    // cin >> s;
    int n = s.length();
    unordered_map <char, int> hash;
    for(int i = 0; i < n; i++) {
        hash[s[i]]++;
    }
    priority_queue <Node*, vector<Node*>, comp> pq;
    for(auto it: hash) {
        pq.push(convert(it.first, it.second, NULL, NULL));
    }
    while(pq.size() != 1) {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        int sum = left -> freq + right -> freq;
        pq.push(convert('\0', sum, left, right));
    }
    Node *root = pq.top();
    unordered_map <char, string> huffman;
    encode(root, "", huffman);
    int cnt = 0;
    for(auto it: huffman) {
        cout << it.first << " " << it.second << endl;
        cnt += it.second.length();
    }
    // cout << cnt << endl;
    string huf_encode = "";
    for(auto it: s) {
        huf_encode += huffman[it];
    }
    cout << huf_encode << endl;
}