// Question Link - https://www.interviewbit.com/problems/2sum-binary-tree/
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
unordered_set<int> mp;
bool ans;
void inorder(TreeNode* A, int B)
{
    if(ans) return;
    if(A==NULL) return;
    inorder(A->left, B);
    if(mp.find(A->val) != mp.end()) ans = 1;
    else mp.insert(B-A->val);
    inorder(A->right, B);
}
int Solution::t2Sum(TreeNode* A, int B) {
    if(A == NULL) return 0;
    mp.clear();
    ans=0;
    inorder(A, B);
    return ans;
}
