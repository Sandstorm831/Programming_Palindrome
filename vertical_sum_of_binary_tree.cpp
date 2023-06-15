// Question Link - https://www.interviewbit.com/problems/vertical-sum-of-a-binary-tree/
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
map<int,int> mp;
void preorder(TreeNode* A, int level)
{
    // cout<<level<<endl;
    if(A==NULL) return;
    preorder(A->left, level-1);
    if(mp.find(level) == mp.end()) mp[level] = A->val;
    else mp[level] += A->val;
    // cout<<" | "<<level<<" "<<mp[level]<<" | "<<endl;
    preorder(A->right, level+1);   
}
vector<int> Solution::verticalSum(TreeNode* A) {
    // if(A==NULL) return 0;
    mp.clear();
    preorder(A, 0);
    vector<int> ans;
    for(auto itr = mp.begin(); itr!=mp.end(); itr++)
    {
        ans.push_back(itr->second);
    }
    return ans;
}
