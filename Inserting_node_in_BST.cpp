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
void inserter(node* head, int val){
    node* ndoe = new node(val);
    node* param = head;
    while(true){
        if(param->data > val)
        {
            if(param->left == NULL)
            {
                param->left = ndoe;
                break;
            }
            param = param->left;
        }
        else
        {
            if(param->right == NULL)
            {
                param->right = ndoe;
                break;
            }
            param = param->right;
        }
    }
}
void inordertraversal(node* head){
    if(head == NULL) return;
    inordertraversal(head->left);
    cout<<head->data<<" ";
    inordertraversal(head->right);
}
int main()
{
    int root;
    cout<<"Enter the root node data, -1 for empty node"<<endl;
    cin>>root;
    node* head = binarytreeformer(root);
    /*
    Following tree is constructed;
                         4
                       /   \
                      2     6
                     / \   / \
                    1   3  5  7
    */
   int val = 8;
   inserter(head, val);
   inordertraversal(head);

}