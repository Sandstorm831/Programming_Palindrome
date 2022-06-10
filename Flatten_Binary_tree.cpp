// Problem Link - https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/
/** Problem Solution Function --------------------------------------------+
 * Definition for binary tree                                             |  
 * struct TreeNode {                                                      |  
 *     int val;                                                           |  
 *     TreeNode *left;                                                    |  
 *     TreeNode *right;                                                   |      
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}               |  
 * };                                                                     |  
 *                                                                        |  
void reorderbinary(TreeNode* head, TreeNode** prev)         <-------------+
{
    if(head == NULL) return;
    if(*prev == NULL) {
        *prev = head;
    }
    else
    {
        (*prev)->left = head;
        *prev = head;
    }
    reorderbinary(head->left, prev);
    reorderbinary(head->right, prev);
}
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    TreeNode* prev = NULL;
    reorderbinary(A, &prev);
    TreeNode* curr = A;
    while(curr != NULL)
    {
        curr->right = curr->left;
        curr->left = NULL;
        curr = curr->right;
    }
    return A;
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
// This is for inorder traversal
void reorderbinary(node* head, node** prev, node** base)
{
    if(head == NULL) return;
    reorderbinary(head->left, prev, base);
    if(*base == NULL) {
        *base = head;
        *prev = head;
    }
    else
    {
        head->left = *prev;
        (*prev)->right = head;
        *prev = head;
    }
    reorderbinary(head->right, prev, base);
}

int main()
{
    int root;
    cout<<"Enter the root node data, -1 for empty node"<<endl;
    cin>>root;
    node* head = binarytreeformer(root);
    node* prev = NULL; node* base = NULL;
    reorderbinary(head, &prev, &base);
    node* curr = base;
    while(curr != NULL)
    {
        cout<<curr->data<<" ";
        curr = curr->right;
    }
}