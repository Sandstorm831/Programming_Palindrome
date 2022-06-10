//Problem Link - https://www.interviewbit.com/problems/symmetric-binary-tree/
/** Problem Solution Function -------------------------------------------------+
 * Definition for binary tree                                                  |     
 * struct TreeNode {                                                           | 
 *     int val;                                                                | 
 *     TreeNode *left;                                                         | 
 *     TreeNode *right;                                                        | 
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}                    | 
 * };                                                                          |     
 *                                                                             | 
void inordertraversal(TreeNode* head, vector<int>& stored){     <--------------+
    if(head == NULL) return;
    inordertraversal(head->left, stored);
    stored.push_back(head->val);
    inordertraversal(head->right, stored);
}
int Solution::isSymmetric(TreeNode* A) {
    vector<int> stored;
    vector<int> glored;
    inordertraversal(A->left, stored);
    inordertraversal(A->right,glored);
    if(stored.size() != glored.size()) return false;
    for (int i = 0; i < stored.size(); i++)
    {
        if(stored[i] != glored[stored.size() -1 -i]) return false;
    }
    return true;
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

void inordertraversal(node* head, vector<int>& stored){
    if(head == NULL) return;
    inordertraversal(head->left, stored);
    stored.push_back(head->data);
    inordertraversal(head->right, stored);
}
int main()
{
    int root;
    cout<<"Enter the root node data, -1 for empty node"<<endl;
    cin>>root;
    node* head = binarytreeformer(root);
    vector<int> stored;
    vector<int> glored;
    inordertraversal(head, stored);
    inordertraversal(head, glored);
    if(stored.size() != glored.size()) cout<<0;
    for (int i = 0; i < stored.size(); i++)
    {
        if(stored[i] != glored[stored.size() -1 -i]) cout<<0;
    }
    cout<<1;
    

}