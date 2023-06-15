// Question Link - https://www.interviewbit.com/problems/cousins-in-binary-tree/
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
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if(A->val == B) return ans;
    queue<TreeNode*> q;
    q.push(A);
    q.push(NULL);
    bool found=false;
    while(!q.empty())
    {
        TreeNode* p = q.front();
        q.pop();
        if(p == NULL)
        {
            if(q.empty()) break;
            q.push(NULL);
            if(found) break;
            ans.clear();
            found = false;
        }
        else
        {
            if(p->left != NULL && p->right != NULL)
            {
                if(p->left->val != B && p->right->val != B)
                {
                    ans.push_back(p->left->val);
                    ans.push_back(p->right->val);
                }
                else found = true;
                q.push(p->left);
                q.push(p->right);
            }
            else if(p->left != NULL)
            {
                if(p->left->val != B)
                {
                    ans.push_back(p->left->val);
                }
                else found = true;
                q.push(p->left);
            }
            else if(p->right != NULL)
            {
                if(p->right->val != B)
                {
                    ans.push_back(p->right->val);
                }
                else found = true;
                q.push(p->right);
            }
        }
    }
    return ans;
}
