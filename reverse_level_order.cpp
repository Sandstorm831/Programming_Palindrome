// Question Link - https://www.interviewbit.com/problems/reverse-level-order/
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
vector<int> Solution::solve(TreeNode* A) {
    vector<int> ans;
    if(A==NULL) return ans;
    queue<TreeNode*> q;
    q.push(A);
    q.push(NULL);
    vector<vector<int>> an;
    vector<int> dumy;
    while(!q.empty())
    {
        TreeNode* p = q.front();
        q.pop();
        if(p == NULL)
        {
            if(q.empty()) 
            {
                an.push_back(dumy);
                dumy.clear();
                break;
            }
            else
            {
                q.push(NULL);
                an.push_back(dumy);
                dumy.clear();   
            }
        }
        else
        {
            dumy.push_back(p->val);
            if(p->left != NULL)
            {
                q.push(p->left);
            }
            if(p->right != NULL)
            {
                q.push(p->right);
            }
        }
    }
    for(int i=an.size()-1; i>=0; i--)
    {
        for(int j=0; j<an[i].size(); j++)
        {
            ans.push_back(an[i][j]);
        }
    }
    return ans;
}
