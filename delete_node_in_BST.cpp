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

void inordertraversal(node* head){
    if(head == NULL) return;
    inordertraversal(head->left);
    cout<<head->data<<" ";
    inordertraversal(head->right);
}
// void preordertraversal(node* head)
// {
//     if(head == NULL) return;
//     cout<<head->data<<" ";
//     preordertraversal(head->left);
//     preordertraversal(head->right);

// }
// void postordertraversal(node* head)
// {
//     if(head == NULL) return;
//     postordertraversal(head->left);
//     postordertraversal(head->right);
//     cout<<head->data<<" ";
// }
node* minimumelementnode(node* head)
{
    if(head->left == NULL) return head;
    else minimumelementnode(head->left);
}
node* nodedeleter(node* head, int target)
{
    if(head == NULL) return NULL;
    if(target < head->data) head->left = nodedeleter(head->left, target);
    else if(target > head->data)head->right = nodedeleter(head->right, target);
    else
    {
        if(head->left ==  NULL)
        {
            return head->right;
        }
        else if(head->right ==  NULL)
        {
            return head->left;
        }
        else
        {
            node* miny = minimumelementnode(head->right);
            head->data = miny->data;
            head->right = nodedeleter(head->right, miny->data);
            return head;
        }
    }
    return head;
}
int main()
{
    int root;
    cout<<"Enter the root node data, -1 for empty node"<<endl;
    cin>>root;
    node* head = binarytreeformer(root);
    inordertraversal(head);
    int target = 8;
    node* base = nodedeleter(head, target);
    inordertraversal(base);
}