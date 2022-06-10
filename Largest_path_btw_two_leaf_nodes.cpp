// Problem Link - https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/
/** Problem solution function --------------------------------------------+
 * Definition for binary tree                                             |  
 * struct TreeNode {                                                      |  
 *     int val;                                                           |  
 *     TreeNode *left;                                                    |      
 *     TreeNode *right;                                                   |
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}               |  
 * };                                                                     |  
 *                                                                        |  
int maxpathsum(TreeNode* head, int& maxy)                 <---------------+
{
    if(head == NULL) return -914748354;
    int leftsum = maxpathsum(head->left, maxy);
    int rightsum = maxpathsum(head->right, maxy);
    maxy = max(max(max(max(max(max(leftsum, rightsum),leftsum+head->val),rightsum+head->val),leftsum+rightsum+head->val), head->val),maxy);
    return max(max(leftsum+head->val, rightsum+head->val), head->val);
}
int Solution::maxPathSum(TreeNode* A) {
    int maxy = INT_MIN;
    int soros = maxpathsum(A, maxy);
    return maxy;
    
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
int maxpathsum(node* head, int& maxy)
{
    if(head == NULL) return -947483648;
    int leftsum = maxpathsum(head->left, maxy);
    int rightsum = maxpathsum(head->right, maxy);
    maxy = max(max(max(max(max(max(leftsum, rightsum),leftsum+head->data),rightsum+head->data),leftsum+rightsum+head->data), head->data),maxy);
    return max(max(leftsum+head->data, rightsum+head->data), head->data);
}
int main()
{
    int root;
    cout<<"Enter the root node data, -1 for empty node"<<endl;
    cin>>root;
    node* head = binarytreeformer(root);
    int maxy = INT_MIN;
    int helen = maxpathsum(head, maxy);
    cout<<maxy;
}