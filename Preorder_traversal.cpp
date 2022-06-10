// Problem Link - https://www.interviewbit.com/problems/preorder-traversal/
/** problem solution function -------------------------------------------+
 * Definition for binary tree                                            |   
 * struct TreeNode {                                                     |   
 *     int val;                                                          |   
 *     TreeNode *left;                                                   |   
 *     TreeNode *right;                                                  |   
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}              |   
 * };                                                                    |   
 *                                                                       |   
void preordertraversal(TreeNode* head, vector<int>& solver)       <------+
{
    if(head == NULL) return;
    solver.push_back(head->val);
    preordertraversal(head->left, solver);
    preordertraversal(head->right, solver);

}
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> solver;
    preordertraversal(A, solver);
    return solver;
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
void preordertraversal(node* head)
{
    if(head == NULL) return;
    cout<<head->data<<" ";
    preordertraversal(head->left);
    preordertraversal(head->right);

}
int main()
{
    int root;
    cout<<"Enter the root node data, -1 for empty node"<<endl;
    cin>>root;
    node* head = binarytreeformer(root);
    cout<<endl<<"Preorder traversal"<<endl;
    preordertraversal(head);
}