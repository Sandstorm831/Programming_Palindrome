//Problem Link - https://www.interviewbit.com/problems/min-depth-of-binary-tree/
/** Problem Solution function ---------------------------------------+
 * Definition for binary tree                                        |   
 * struct TreeNode {                                                 |
 *     int val;                                                      |
 *     TreeNode *left;                                               |
 *     TreeNode *right;                                              |
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}          |
 * };                                                                |
 *                                                                   |
int depthi(TreeNode* A){            <--------------------------------+
    if(!A) return INT_MAX;
    if(!A->left && !A->right) return 1;
    return min(depthi(A->left), depthi(A->right)) + 1;
}
int Solution::minDepth(TreeNode* A) {
    if(!A) return 0;
    if(!A->left && !A->right) return 1;
    return depthi(A);
}
*/
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
int depthi(node* head){
    if(!head) return INT_MAX;
    if(!head->left && !head->right) return 1;
    return min(depthi(head->left), depthi(head->right)) + 1;
}
int minDepth(node* head) {
    if(!head) return 0;
    if(!head->left && !head->right) return 1;
    return depthi(head);
}

int main()
{
    int root;
    cout<<"Enter the root node data, -1 for empty node"<<endl;
    cin>>root;
    node* head = binarytreeformer(root);
    cout<<"min height of binary tree = "<<minDepth(head);
}