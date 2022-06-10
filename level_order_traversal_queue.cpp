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
void leveltraversal(node* head, vector<int>& ansy){
    queue<node*> checker;
    checker.push(head);
    while(!checker.empty())
    {

        ansy.push_back(checker.front()->data);
        if(checker.front()->left  != NULL) checker.push(checker.front()->left);
        if(checker.front()->right != NULL) checker.push(checker.front()->right);
        checker.pop();
    }
}
int main()
{
    int root;
    cout<<"Enter the root node data, -1 for empty node"<<endl;
    cin>>root;
    node* head = binarytreeformer(root);
    vector<int> ansy;
    leveltraversal(head,ansy);
    for (int i = 0; i < ansy.size(); i++)
    {
        cout<<ansy[i]<<" ";
    }
    
}