// Question LInk - https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/
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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> ans;
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
    for(int i=0; i<an.size(); i++)
    {
        if(i%2==0)
        { 
            ans.push_back(an[i]);
        }
        else if(i%2==1)
        {
            vector<int> d = an[i];
            reverse(d.begin(), d.end());
            ans.push_back(d);
        }
    }
    return ans;
}
