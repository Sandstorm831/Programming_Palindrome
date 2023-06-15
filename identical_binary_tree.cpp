// Question Link - https://www.interviewbit.com/problems/identical-binary-trees/
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
bool comparer(TreeNode* A, TreeNode* B)
{
    if(A==NULL && B==NULL) return true;
    else if(A==NULL) return false;
    else if(B==NULL) return false;
    else if(A->val != B->val) return false;
    return (comparer(A->left, B->left) && comparer(A->right, B->right));
}
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(A==NULL && B==NULL) return true;
    else if(A==NULL) return false;
    else if(B==NULL) return false;
    else if(A->val != B->val) return false;
    return comparer(A, B);
}
