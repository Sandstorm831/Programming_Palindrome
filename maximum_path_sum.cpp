/* Problem Link - https://leetcode.com/problems/binary-tree-maximum-path-sum/
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them.
A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.
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
int sumFinder(node* head, int& res)
{
    if(head == NULL) return 0;
    int left = sumFinder(head->left, res);
    int right = sumFinder(head->right, res);
    int temp = max(max(left,right)+head->val, head->val);
    int maxy = max(temp, left+right+head->val);
    res = max(res, maxy);
    return temp;
}
int main()
{
    cout<<"enter root node value, enter -1 to terminate the branch"<<endl;
    int head;
    cin>>head;
    node* headnode = treebuilder(head);
    int res = INT_MIN;
    sumFinder(headnode, res);
    cout<<res;
}