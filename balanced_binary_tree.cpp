// Question Link - https://www.interviewbit.com/problems/balanced-binary-tree/
// Solution

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ans = true;
int height(TreeNode* A)
{
    if(A==NULL) return 0;
    int l = height(A->left);
    int r = height(A->right);
    if(abs(l-r)>1) ans=false;
    return 1+max(l,r);
}
int Solution::isBalanced(TreeNode* A) {
    ans=true;
    int x = height(A);
    return ans;
}
