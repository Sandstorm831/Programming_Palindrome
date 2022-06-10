// Problem Link - https://www.interviewbit.com/problems/path-to-given-node/
/**Problem Solution Function ----------------------------------------------+
 * Definition for binary tree                                              | 
 * struct TreeNode {                                                       |     
 *     int val;                                                            | 
 *     TreeNode *left;                                                     | 
 *     TreeNode *right;                                                    |     
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}                | 
 * };                                                                      |     
 *                                                                         | 
void inordertraversal(TreeNode* head, int B, vector<int>& brutus){      <--+
    if(head == NULL) return;
    brutus.push_back(head->val);
    if(head->val == B) 
    {
        return;
    }
    inordertraversal(head->left, B, brutus);
    inordertraversal(head->right, B, brutus);
    if(brutus[brutus.size()-1] != B ) brutus.pop_back();
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> brutus;
    inordertraversal(A, B, brutus);
    return brutus;
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

void pathnode(node* head, int B, vector<int>& brutus){
    if(head == NULL) return;
    brutus.push_back(head->data);
    if(head->data == B) 
    {
        hellyou = brutus;
        return;
    }
    pathnode(head->left, B, brutus);
    pathnode(head->right);
    if(brutus[brutus.size()-1] != B ) brutus.pop_back();
}
int main()
{
    int root;
    cout<<"Enter the root node data, -1 for empty node"<<endl;
    cin>>root;
    node* head = binarytreeformer(root);

}