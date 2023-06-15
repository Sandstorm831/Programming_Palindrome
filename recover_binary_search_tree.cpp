// Question LInk - https://www.interviewbit.com/problems/recover-binary-search-tree/
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
vector<int> inor;
void inorder(TreeNode* A)
{
    if(A==NULL) return ;
    inorder(A->left);
    inor.push_back(A->val);
    inorder(A->right);
}
vector<int> Solution::recoverTree(TreeNode* A) {
    inor.clear();
    inorder(A);
    int f=-1,b=-1;
    for(int i=0; i<inor.size()-1; i++)
    {
        if(inor[i]>inor[i+1])
        {
            if(f==-1 && b==-1)
            {
                f=inor[i+1];
                b=inor[i];
            }
            else
            {
                f = inor[i+1];
            }
        }
    }
    
    vector<int> v;
    v.push_back(f);
    v.push_back(b);
    return v;
}
