// Problem Link - https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/
/** Problem solution function --------------------------------------------------------------------------------------+                 
 * Definition for binary tree                                                                                       |         
 * struct TreeNode {                                                                                                | 
 *     int val;                                                                                                     |                 
 *     TreeNode *left;                                                                                              | 
 *     TreeNode *right;                                                                                             | 
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}                                                         | 
 * };                                                                                                               | 
 *                                                                                                                  | 
void pathsum(TreeNode* head, int& sumer, int target, vector<int>& sumerhead, vector<vector<int>>& read)   <---------+
{
    if(head == NULL) return;
    sumer += head->val;
    sumerhead.push_back(head->val);
    if(head->left == NULL && head->right == NULL)
    {
        if(sumer == target) 
        {   
            read.push_back(sumerhead);
        }
        else
        {
            sumer -= head->val;
            sumerhead.pop_back();
            return;
        } 
    }
    pathsum(head->left,sumer, target, sumerhead, read);
    pathsum(head->right, sumer, target, sumerhead, read);
    sumer -= head->val;
    sumerhead.pop_back();

}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<int> sumerhead;
    vector<vector<int>> read;
    int sumer = 0;
    pathsum(A, sumer, B, sumerhead, read);
    return read;

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
void pathsumpath(node* head, int& sumer, int target, vector<int>& sumerhead, vector<vector<int>>& read)
{
    if(head == NULL) return;
    sumer += head->data;
    sumerhead.push_back(head->data);
    if(head->left == NULL && head->right == NULL)
    {
        if(sumer == target) 
        {   
            read.push_back(sumerhead);
        }
        else
        {
            sumer -= head->data;
            return;
        } 
    }
    pathsumpath(head->left,sumer, target, sumerhead, read);
    pathsumpath(head->right, sumer, target, sumerhead, read);
    sumer -= head->data;
    sumerhead.pop_back();

}

int main()
{
    int root;
    cout<<"Enter the root node data, -1 for empty node"<<endl;
    cin>>root;
    node* head = binarytreeformer(root);
    int sumer = 0;
    int target = 22;
    vector<int> sumerhead;
    vector<vector<int>> read;
    pathsumpath(head, sumer, target, sumerhead, read);
    for (int i = 0; i < read.size(); i++)
    {
        for (int j = 0; j < read[i].size(); j++)
        {
            cout<<read[i][j]<<" ";
        }
        cout<<endl;
        
    }
}