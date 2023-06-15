// Question Link - https://www.interviewbit.com/problems/consecutive-parent-child/
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
int ans;
void inorder(TreeNode* A)
{
    if(A == NULL) return;
    if(A->left != NULL)
    {
        if(abs(A->left->val - A->val)==1) ans++;
    }
    if(A->right != NULL)
    {
        if(abs(A->right->val - A->val) == 1) ans++;
    }
    inorder(A->left);inorder(A->right);
}
int Solution::consecutiveNodes(TreeNode* A) {
    ans=0;
    inorder(A);
    return ans;
}