/*Problem Link - https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/
 * Problem Solution Function -------------------------------------------------------------------------------------------+
 * Definition for binary tree                                                                                           |
 * struct TreeNode {                                                                                                    |
 *     int val;                                                                                                         |
 *     TreeNode *left;                                                                                                  |
 *     TreeNode *right;                                                                                                 | 
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}                                                             | 
 * };                                                                                                                   |
 *                                                                                                                      |
int finder(vector<int>& inorder, int i,int  j,int value)        <-------------------------------------------------------+
{
    for(auto k =i; k<=j; ++k)
    {
        if(inorder[k] == value) return k;
    }   
}
TreeNode* preandinordertotree(vector<int>& inorder, vector<int>& preorder, int i, int j, int& preo)
{
    if(i>j) return NULL;
    TreeNode* head = new TreeNode(preorder[preo]);
    preo++;
    if(i == j) return head;
    int partioner = finder(inorder, i,j, head->val);
    head->left = preandinordertotree(inorder, preorder, i, partioner-1, preo);
    head->right = preandinordertotree(inorder, preorder, partioner+1, j, preo);
    return head;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    if(A.size() == 0|| B.size() == 0) return NULL;
    int preo = 0;
    return preandinordertotree(B,A,0,A.size()-1, preo);
}
*/
#include <bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};
int finder(vector<int>& inorder, int i,int  j,int value)
{
    for(auto k =i; k<=j; ++k)
    {
        if(inorder[k] == value) return k;
    }   
}
TreeNode* preandinordertotree(vector<int>& inorder, vector<int>& preorder, int i, int j, int& preo)
{
    if(i>j) return NULL;
    TreeNode* head = new TreeNode(preorder[preo]);
    preo++;
    if(i == j) return head;
    int partioner = finder(inorder, i,j, head->val);
    head->left = preandinordertotree(inorder, preorder, i, partioner-1, preo);
    head->right = preandinordertotree(inorder, preorder, partioner+1, j, preo);
    return head;
}
void preordertraversal(TreeNode* head)
{
    if(head == NULL) return;
    cout<<head->val<<" ";
    preordertraversal(head->left);
    preordertraversal(head->right);

}
int main()
{
    vector<int> inorder; vector<int> preorder;
    inorder = {4,3,5,2,6,10,9,12,11,8,7,1,13,14,17,16,19,18,21,20,22,15};
    preorder = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22};
    if(inorder.size() == 0|| preorder.size() == 0) cout<<-1;
    int preo = 0;
    TreeNode* atomiser = preandinordertotree(inorder,preorder,0,preorder.size()-1, preo);
    preordertraversal(atomiser);
}