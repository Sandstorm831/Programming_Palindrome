// Problem Link - https://www.interviewbit.com/problems/least-common-ancestor/
/**Problem Solution function ------------------------------------------------------+
 * Definition for binary tree                                                      |                             
 * struct TreeNode {                                                               | 
 *     int val;                                                                    | 
 *     TreeNode *left;                                                             | 
 *     TreeNode *right;                                                            | 
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}                        |     
 * };                                                                              | 
 *                                                                                 | 
int pathfinder(TreeNode* head, int alpha, int beta)              <-----------------+ 
{
    if(head == NULL) return -1;
    if(head->val == alpha || head->val== beta) return head->val;
    int lefter = pathfinder(head->left, alpha, beta);
    int righter = pathfinder(head->right, alpha, beta);
    if(lefter == -1 && righter == -1) return -1;
    else if(lefter == -1) return righter;
    else if(righter == -1) return lefter;
    else return head->val;
}
void finder(TreeNode* A, int B, int C, vector<int>& verdict)
{
    if(A == NULL) return;
    if(A->val == B || A->val == C)
    {
        verdict.push_back(A->val);
    }
    finder(A->left, B,C, verdict);
    finder(A->right, B,C, verdict);
}
int Solution::lca(TreeNode* A, int B, int C) {
    vector<int> verdict;
    finder(A,B,C,verdict);
        if(B==C){
            if(verdict.size() == 1){
                int hell = pathfinder(A,B, C);
                return hell;
            }
        }
        if(B != C)
        {
            if(verdict.size() == 2){
                int hell = pathfinder(A,B, C);
                return hell;
            } 
        }
        return -1;
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
int pathfinder(node* head, int alpha, int beta)
{
    if(head == NULL) return -1;
    if(head->data == alpha || head->data == beta) return head->data;
    int lefter = pathfinder(head->left, alpha, beta);
    int righter = pathfinder(head->right, alpha, beta);
    if(lefter == -1 && righter == -1) return -1;
    else if(lefter == -1) return righter;
    else if(righter == -1) return lefter;
    else return head->data;
}
void finder(node* A, int B, int C, vector<int>& verdict)
{
    if(A == NULL) return;
    if(A->data == B || A->data == C)
    {
        verdict.push_back(A->data);
    }
    finder(A->left, B,C, verdict);
    finder(A->right, B,C, verdict);
}
int main()
{
    int root;
    cout<<"Enter the root node data, -1 for empty node"<<endl;
    cin>>root;
    node* head = binarytreeformer(root);
    vector<int> verdict;
    int alpha = 12;
    int beta = 9;
    finder(head, alpha, beta, verdict);
    if(alpha==beta){
        if(verdict.size() == 1){
            int hell = pathfinder(head,beta, alpha);
            cout<<hell;
        }
    }
    if(alpha != beta)
    {
        if(verdict.size() == 2){
            int hell = pathfinder(head,alpha, beta);
            cout<<hell;
        } 
    }
    cout<<-1;
    
}