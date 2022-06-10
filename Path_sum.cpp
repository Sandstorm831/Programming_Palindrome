// Problem Link - https://www.interviewbit.com/problems/path-sum/
/** Problem solution function -----------------------------------------+
 * Definition for binary tree                                          |         
 * struct TreeNode {                                                   | 
 *     int val;                                                        |                 
 *     TreeNode *left;                                                 | 
 *     TreeNode *right;                                                | 
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}            | 
 * };                                                                  | 
 *                                                                     | 
void pathsum(TreeNode* head, bool& haply, int& sumer, int target)   <--+
{
    if(head == NULL) return;
    sumer += head->val;
    if(head->left == NULL && head->right == NULL)
    {
        if(sumer == target) haply = true;
        else
        {
            sumer -= head->val;
            return;
        } 
    }
    pathsum(head->left, haply, sumer, target);
    pathsum(head->right, haply, sumer, target);
    sumer -= head->val;

}
int Solution::hasPathSum(TreeNode* A, int B) {
    int sumer = 0;
    bool haply = false;
    pathsum(A, haply, sumer, B);
    return haply==true?1:0;

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
void pathsum(node* head, bool& haply, int& sumer, int target)
{
    if(head == NULL) return;
    sumer += head->data;
    if(head->left == NULL && head->right == NULL)
    {
        cout<<sumer<<" target is ->"<<target<<" here is haply"<<haply<<endl;
        if(sumer == target) 
        {
            cout<<sumer<<" target is ->"<<target<<" here is haply"<<haply<<endl;
            haply = true;
        }
        else
        {
            sumer -= head->data;
            return;
        } 
    }
    pathsum(head->left, haply, sumer, target);
    pathsum(head->right, haply, sumer, target);
    sumer -= head->data;

}

int main()
{
    int root;
    cout<<"Enter the root node data, -1 for empty node"<<endl;
    cin>>root;
    node* head = binarytreeformer(root);
    int sumer = 0;
    int target = 1;
    bool haply = false;
    pathsum(head, haply, sumer, target);
    cout<<haply;
    
}