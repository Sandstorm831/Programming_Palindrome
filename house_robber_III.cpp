// Question LInk - https://leetcode.com/problems/house-robber-iii/description/
// Solution 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int recursor(TreeNode* root, int& l, int& r)
    {
        if(!root) return 0;
        int ll=0,lr=0,rr=0,rl=0;
        l = recursor(root->left, ll, lr);
        r = recursor(root->right, rl, rr);
        return max(root->val+ll+rl+rr+lr, l+r);
    }
    int rob(TreeNode* root) {
        int l, r;
        return recursor(root, l, r);
    }
};