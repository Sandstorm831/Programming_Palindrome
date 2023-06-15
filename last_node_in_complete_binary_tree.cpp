// Question Link - https://www.interviewbit.com/problems/last-node-in-a-complete-binary-tree/
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
int Solution::lastNode(TreeNode* A) {
    if(A==NULL) return NULL;
    int ans=A->val;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty())
    {
        TreeNode* x = q.front();
        q.pop();
        if(x->left != NULL) q.push(x->left);
        if(x->right != NULL) q.push(x->right);
        ans = x->val;
    }
    return ans;
}
