#include <bits/stdc++.h>
using namespace std;
const int ALPHABET_SIZE = 26;
struct TrieNode
{
    TrieNode* children[ALPHABET_SIZE];
    bool isend;
    TrieNode()
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            children[i] = NULL;
        }
        isend = false;
    }
};
void insert(struct TrieNode* root, string key)
{
    struct TrieNode* root_base = root;
    for (int i = 0; i < key.size(); i++)
    {
        int index = key[i] - 'a';
        if(!root_base->children[index]) root_base->children[index] = new Trienode;
        root_base = root_base->children[index];
    }
    root_base->isend =true;
}
bool search(struct TrieNode* root, string key)
{
    struct TrieNode* root_base = root;
    int index;
    for (int i = 0; i < key.size(); i++)
    {
        index = key[i]-'a';
        if(!root_base->children[index]) return false;
        root_base = root_base->children[index];
    }
    return (root_base->isend);
}
int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    struct TrieNode *root = getnode();
 
    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
 
    // Search for different keys
    search(root, "the")? cout << "Yes\n" :
                         cout << "No\n";
    search(root, "these")? cout << "Yes\n" :
                           cout << "No\n";
    search(root, "their")? cout << "Yes\n" :
                         cout << "No\n";
    search(root, "thaw")? cout << "Yes\n" :
                           cout << "No\n";
    return 0;
}