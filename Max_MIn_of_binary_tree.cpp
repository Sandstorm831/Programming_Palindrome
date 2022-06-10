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
int minofbinarytree(node* head)
{
    if(head == NULL) return INT_MAX;
    return min(min(minofbinarytree(head->left), minofbinarytree(head->right)), head->data);
}
int maxofbinarytree(node* head)
{
    if(head == NULL) return INT_MIN;
    return max(max(maxofbinarytree(head->left), maxofbinarytree(head->right)), head->data);
}
int main()
{
    int root;
    cout<<"Enter the root node data, -1 for empty node"<<endl;
    cin>>root;
    node* head = binarytreeformer(root);
    cout<<"minimum node value of binary tree = "<<minofbinarytree(head)<<endl;
    cout<<"maximum node value of binary tree = "<<maxofbinarytree(head);
}