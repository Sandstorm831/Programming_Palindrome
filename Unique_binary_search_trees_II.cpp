// Question Link - https://leetcode.com/problems/unique-binary-search-trees-ii/description/
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
    vector<TreeNode*> helper(int ini, int fin)
    {
        vector<TreeNode*> ans;
        if(ini>fin)
        {
            ans.push_back(NULL);
            return ans;
        }
        for(int i=ini; i<=fin; i++)
        {
            vector<TreeNode*> l = helper(ini,i-1);
            vector<TreeNode*> r = helper(i+1,fin);
            for(int j=0; j<l.size(); j++)
            {
                for(int k=0; k<r.size(); k++)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = l[j];
                    root->right = r[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }
};