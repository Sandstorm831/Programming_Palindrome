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

void inordertraversal(node* head, int& eternal, bool& verdict){
    if(head == NULL) return;
    inordertraversal(head->left, eternal, verdict);
    if(eternal > head->data) verdict = false;
    else eternal = head->data;
    inordertraversal(head->right, eternal, verdict);
}
int main()
{
    int root;
    cout<<"Enter the root node data, -1 for empty node"<<endl;
    cin>>root;
    node* head = binarytreeformer(root);
    bool verdict = true;
    int eternal = INT_MIN;
    inordertraversal(head, eternal, verdict);
    cout<<verdict;
}