// Question Link -  https://www.interviewbit.com/problems/covered-uncovered-nodes/
// Solution 

/**
 * Definition for binary tree
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(long long x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void preorder(TreeNode* A, long long& summ)
{
    if(A==NULL) return;
    preorder(A->left, summ);
    summ += A->val;
    preorder(A->right, summ);
}
long Solution::coveredNodes(TreeNode* A) {
    long long summ=0;
    preorder(A, summ);
    long long nm = 0;
    vector<TreeNode*> dum;
    queue<TreeNode*> q;
    q.push(A);
    q.push(NULL);
    long long prev=0;
    while(!q.empty())
    {
        TreeNode* cur = q.front();
        q.pop();
        if(cur == NULL)
        {
            if(q.empty()) break;
            else
            {
                q.push(NULL);
                if(dum.size()==1) nm += dum[0]->val;
                else nm += dum[0]->val+dum.back()->val;
                dum.clear();
                // cout<<endl<<" {"<<nm<<"} "<<endl;
            }
        }
        else
        {
            if(cur->left != NULL) q.push(cur->left);
            if(cur->right != NULL) q.push(cur->right);
            dum.push_back(cur);
            // cout<<cur->val<<" | ";
            
        }
    }
    if(dum.size()==1) nm += dum[0]->val;
    else nm += dum[0]->val+dum.back()->val;
    // cout<<summ<<" "<<nm<<endl;
    return abs(summ-2*nm);
}
