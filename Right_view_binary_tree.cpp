// Problem Link - https://www.interviewbit.com/problems/right-view-of-binary-tree/
/*Problem Solution Function ------------------------------------------------------------+
 * Definition for binary tree                                                           |
 * struct TreeNode {                                                                    |
 *     int val;                                                                         |    
 *     TreeNode *left;                                                                  |
 *     TreeNode *right;                                                                 |
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}                             |
 * };                                                                                   |
 *                                                                                      |
void rightviewer(TreeNode* head, unordered_map<int,int>& ansy, int level)    <----------+
{
    if(head == NULL) return;
    if(ansy.find(level) == ansy.end()) ansy[level] = head->val;
    rightviewer(head->right, ansy ,level+1);
    rightviewer(head->left, ansy, level+1);
}
vector<int> Solution::solve(TreeNode* A) {
    unordered_map<int,int> ansy;
    rightviewer(A, ansy, 1);
    vector<int> bansy;
    for (int i = 1; i <= ansy.size(); i++)
    {
        bansy.push_back(ansy[i]);
    }
    return bansy;
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
void rightviewer(node* head, unordered_map<int,int>& ansy, int level)
{
    if(head == NULL) return;
    if(ansy.find(level) == ansy.end()) ansy[level] = head->data;
    rightviewer(head->right, ansy, level+1);
    rightviewer(head->left, ansy ,level+1);
}

int main()
{
    int root;
    cout<<"Enter the root node data, -1 for empty node"<<endl;
    cin>>root;
    node* head = binarytreeformer(root);
    unordered_map<int,int> ansy;
    rightviewer(head, ansy, 1);
    for (int i = 1; i <= ansy.size(); i++)
    {
        cout<<ansy[i]<<" ";
    }
}