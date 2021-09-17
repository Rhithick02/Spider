#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define lli long long
#define fi first
#define se second
#define mod 1000000007
#define MAX 100001
#define pb push_back
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

struct Trie {
    char ch;
    int wordend;
    Trie *child[26];
};

Trie* getnode(char ch) {
    Trie *temp = new Trie;
    temp -> ch = ch;
    temp -> wordend = 0;
    for(int i = 0; i < 26; i++) {
        temp -> child[i] = NULL;
    }
    return temp;
}
void insert(Trie* &root, string s) {
    Trie *cur = root;
    for(int i = 0; i < s.length(); i++) {
        if(!cur -> child[s[i] - 'a']) {
            cur -> child[s[i]-'a'] = getnode(s[i]);
        }
        cur = cur -> child[s[i]-'a'];
    }
    cur -> wordend += 1;
}
bool search(Trie* &root, string s) {
    Trie *cur = root;
    for(int i = 0; i < s.length(); i++) {
        if(!cur -> child[s[i] - 'a']) {
            return false;
        }
        cur = cur -> child[s[i] - 'a'];
    }
    if(!(cur -> wordend)) {
        return false;
    }
    return true;
}
void remove(Trie* &root, string s, int i) {
    if(i == s.length()) {
        if(root -> wordend == 0) {
            cout << "Word not found\n";
        } else {
            root -> wordend -= 1;
            cout << "Successfully deleted\n";
        }
        return;
    }
    if(root -> child[s[i] - 'a'] == NULL) {
        cout << "Word not found\n";
        return;
    }
    remove(root -> child[s[i] - 'a'], s, i+1);
}

int main() {
    Trie *root = new Trie;
    root->ch = '/';
    root->wordend = false;
    for(int i = 0; i < 26; i++) {
        root -> child[i] = NULL;
    }
    insert(root, "rhithick");
    insert(root, "rhi");
    cout << search(root, "rhi") << endl;
    cout << search(root, "rhit") << endl;
    remove(root, "rhi", 0);
    cout << search(root, "rhi") << endl;
    cout << search(root, "rhithick") << endl;
}