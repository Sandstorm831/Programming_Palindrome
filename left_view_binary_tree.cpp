#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
node* binarytreeformer(int data){
    if(data == -1) return NULL;
    node* ndoe = new node(data);
    int leftnode, rightnode;
    cout<<"enter data of left node of "<<data<<endl;
    cin>>leftnode;
    ndoe->left = binarytreeformer(leftnode);
    cout<<"enter data of right node of "<<data<<endl;
    cin>>rightnode;
    ndoe->right = binarytreeformer(rightnode);
    return ndoe;
}
void leftviewer(node* head, unordered_map<int,int>& ansy, int level)
{
    if(head == NULL) return;
    if(ansy.find(level) == ansy.end()) ansy[level] = head->data;
    leftviewer(head->left, ansy, level+1);
    leftviewer(head->right, ansy ,level+1);
}

int main()
{
    int root;
    cout<<"Enter the root node data, -1 for empty node"<<endl;
    cin>>root;
    node* head = binarytreeformer(root);
    unordered_map<int,int> ansy;
    leftviewer(head, ansy, 1);
    for (int i = 1; i <= ansy.size(); i++)
    {
        cout<<ansy[i]<<" ";
    }
}