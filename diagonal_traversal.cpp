// Question LInk - https://www.interviewbit.com/problems/diagonal-traversal/
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
map<int,vector<int>> mp;
void preorder(TreeNode* A, int level)
{
    if(A == NULL) return;
    preorder(A->left, level+1);
    mp[level].push_back(A->val);
    preorder(A->right, level);
}
vector<int> Solution::solve(TreeNode* A) {
    mp.clear();
    preorder(A, 0);
    vector<int> v;
    for(auto itr=mp.begin(); itr!=mp.end(); itr++)
    {
        for(int i=0; i<itr->second.size(); i++)
        {
            v.push_back(itr->second[i]);
        }
    }
    return v;
}
