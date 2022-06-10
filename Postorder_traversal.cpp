// Problem Link - https://www.interviewbit.com/problems/postorder-traversal/
/** Problem solution function --------------------------------------+
 * Definition for binary tree                                       |    
 * struct TreeNode {                                                |    
 *     int val;                                                     |    
 *     TreeNode *left;                                              |    
 *     TreeNode *right;                                             |
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}         |
 * };                                                               |
 *                                                                  |
void postordertraversal(TreeNode* head, vector<int>& solver)   <----+
{
    if(head == NULL) return;
    postordertraversal(head->left, solver);
    postordertraversal(head->right, solver);
    solver.push_back(head->val);
}
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> solver;
    postordertraversal(A, solver);
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
void postordertraversal(node* head)
{
    if(head == NULL) return;
    postordertraversal(head->left);
    postordertraversal(head->right);
    cout<<head->data<<" ";
}
int main()
{
    int root;
    cout<<"Enter the root node data, -1 for empty node"<<endl;
    cin>>root;
    node* head = binarytreeformer(root);
    cout<<endl<<"postorder traversal"<<endl;
    postordertraversal(head);
}