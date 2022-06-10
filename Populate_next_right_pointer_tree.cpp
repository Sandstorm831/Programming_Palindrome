/** Problem link - https://www.interviewbit.com/problems/populate-next-right-pointers-tree/
 * Problem solution function --------------------------------------------------------------+
 * Definition for binary tree with next pointer.                                           | 
 * struct TreeLinkNode {                                                                   | 
 *  int val;                                                                               | 
 *  TreeLinkNode *left, *right, *next;                                                     |     
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}                   | 
 * };                                                                                      | 
 *                                                                                         | 
TreeLinkNode* nextRight(TreeLinkNode* current)              <------------------------------+
{
    TreeLinkNode* currNext = current->next;
    
    while (currNext)
    {
        if (currNext->left)
            return currNext->left;
        else if (currNext->right)
            return currNext->right;
        currNext = currNext->next;
    }
    return NULL;
}
void Solution::connect(TreeLinkNode* A) {
    if (!A)
        return;
    A->next = NULL;
    while (A)
    {
        TreeLinkNode* B = A;
        while (B)
        {
            if (B->left)
            {
                if (B->right)
                    B->left->next = B->right;
                else
                    B->left->next = nextRight(B);
            }
            if (B->right)
                B->right->next = nextRight(B);
                
            B = B->next;
        }
        if (A->left)
            A = A->left;
        else if (A->right)
            A = A->right;
        else
            A = nextRight(A);
    }
}
*/
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node* left;
    node* right;
    node* next;
    node(int value)
    {
        val = value;
        left = NULL;
        right = NULL;
        next = NULL;
        
    }
};
node* binarytreeformer(int val)
{
    if(val == -1) return NULL;
    node* ndoe = new node(val);
    int leftnode, rightnode;
    cout<<"enter val of left node of "<<val<<endl;
    cin>>leftnode;
    ndoe->left = binarytreeformer(leftnode);
    cout<<"enter val of right node of "<<val<<endl;
    cin>>rightnode;
    ndoe->right = binarytreeformer(rightnode);
    return ndoe;
}
node* rightist(node* current)
{
    node* currNext = current->next;
    
    while (currNext)
    {
        if (currNext->left)
            return currNext->left;
        else if (currNext->right)
            return currNext->right;
        currNext = currNext->next;
    }
    return NULL;
}
void rightpopulator(node* A)
{
    if (!A)
        return;
    A->next = NULL;
    while (A)
    {
        node* B = A;
        while (B)
        {
            if (B->left)
            {
                if (B->right)
                    B->left->next = B->right;
                else
                    B->left->next = rightist(B);
            }
            if (B->right)
                B->right->next = rightist(B);
                
            B = B->next;
        }
        if (A->left)
            A = A->left;
        else if (A->right)
            A = A->right;
        else
            A = rightist(A);
    }
    
}
int main()
{
    int root;
    cout<<"Enter the root node val, -1 for empty node"<<endl;
    cin>>root;
    node* head = binarytreeformer(root);
    rightpopulator(head);
    while(head != NULL)
    {
        node* seek  = head;
        while(head != NULL)
        { 
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
        head = seek;
        if(head->left == NULL) head = head->right;
        else head = head->left;
    }
}