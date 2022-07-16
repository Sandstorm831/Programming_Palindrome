/*
Problem Link - https://www.interviewbit.com/blog/diameter-of-a-binary-tree/
Given a binary tree, find the diameter of the tree.
Diameter: The diameter of a tree is the length of the longest path between any 2 nodes of a tree.
The length of a path is counted as the number of edges lying on that path.
*/
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node* left;
    node* right;
    node()
    {
        left = NULL;
        right = NULL;
    }
};
node* treebuilder(int head)
{
    if(head == -1) return NULL;
    cout<<"Enter value left of "<<head<<endl;
    node* ndoe = new node();
    ndoe->val = head;
    int leftnode, rightnode;
    cin>>leftnode;
    ndoe->left = treebuilder(leftnode);
    cout<<"Enter value right of "<<head<<endl;
    cin>>rightnode;
    ndoe->right = treebuilder(rightnode);
    return ndoe;
}
void inorder(node* head)
{
    if(head == NULL) return;
    inorder(head->left);
    cout<<head->val<<" ";
    inorder(head->right);
}
int treeDiameter(node* head, int& res)
{
    if(head == NULL) return 0;
    int left = treeDiameter(head->left, res);
    int right = treeDiameter(head->right, res);
    int maxy = left+right+1;
    int temp = max(left, right)+1;
    res = max(res, maxy);
    return temp;
}
int main()
{
    cout<<"enter root node value, enter -1 to terminate the branch"<<endl;
    int head;
    cin>>head;
    node* headnode = treebuilder(head);
    // inorder(headnode);
    int res = INT_MIN;
    treeDiameter(headnode, res);
    cout<<res;
}