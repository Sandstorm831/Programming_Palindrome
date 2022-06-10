// Problem Link - https://www.interviewbit.com/problems/burn-a-tree/ 
/** Problem Solution Function --------------------------------------------------------+
 * Definition for binary tree                                                         |  
 * struct TreeNode {                                                                  |  
 *     int val;                                                                       |      
 *     TreeNode *left;                                                                |  
 *     TreeNode *right;                                                               |          
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}                           |      
 * };                                                                                 |  
 *                                                                                    |          
int depthoftree(TreeNode* head)             <-----------------------------------------+
{
    if(head == NULL) return 0;
    return max(depthoftree(head->left), depthoftree(head->right)) + 1;
}
int burndown(TreeNode* head, int target, int& tracker, int& fona)
{
    if(head == NULL) return -1;
    if(head->val == target)
    {
        tracker = 1;
        return tracker;
    }
    int lefter = burndown(head->left, target, tracker, fona);
    int righter ;
    if(lefter == -1) righter = burndown(head->right, target, tracker, fona);
    if(lefter == -1 && righter == -1) return -1;
    else if(lefter > -1)
    {
        tracker++;
        if(fona>0) fona--;
        int hellspore = depthoftree(head->right);
        if(fona < hellspore) fona = hellspore;
        return tracker; 
    }
    else
    {
        tracker++;
        if(fona>0) fona--;
        int hellspore = depthoftree(head->left);
        if(fona < hellspore) fona = hellspore;
        return tracker;    
    }
    
} 
int Solution::solve(TreeNode* A, int B) {
    int tracker, fona =0;
    int l = burndown(A, B,tracker, fona );
    return (fona+l-1);
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
int depthoftree(node* head)
{
    if(head == NULL) return 0;
    return max(depthoftree(head->left), depthoftree(head->right)) + 1;
}
int burndown(node* head, int target, int& tracker, int& fona)
{
    if(head == NULL) return -1;
    if(head->data == target)
    {
        tracker = 1;
        return tracker;
    }
    int lefter = burndown(head->left, target, tracker, fona);
    int righter ;
    if(lefter == -1) righter = burndown(head->right, target, tracker, fona);
    if(lefter == -1 && righter == -1) return -1;
    else if(lefter > -1)
    {
        tracker++;
        if(fona>0) fona--;
        int hellspore = depthoftree(head->right);
        if(fona < hellspore) fona = hellspore;
        return tracker; 
    }
    else
    {
        tracker++;
        if(fona>0) fona--;
        int hellspore = depthoftree(head->left);
        if(fona < hellspore) fona = hellspore;
        return tracker;    
    }
    
} 


int main()
{
    int root;
    cout<<"Enter the root node data, -1 for empty node"<<endl;
    cin>>root;
    node* head = binarytreeformer(root);
    int target = 12, tracker, fona =0;
    int l = burndown(head, target,tracker, fona );
    cout<<fona+l;
}