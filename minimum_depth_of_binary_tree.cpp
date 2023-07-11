// Question Link - https://leetcode.com/problems/minimum-depth-of-binary-tree/description
// solution 

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
    int recursor(TreeNode* root)
    {
        if(root == NULL) return 0;
        int l=-1,r=-1;
        if(root->left != NULL) l = recursor(root->left);
        if(root->right != NULL) r =  recursor(root->right);
        if(l==-1 && r==-1) return 1;
        else if(l==-1) return 1+r;
        else if(r == -1) return 1+l;
        else return (1+min(l,r));
    }
    int minDepth(TreeNode* root) {
        return recursor(root);
    }
};