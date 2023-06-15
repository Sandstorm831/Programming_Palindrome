// Question Link - https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/
// solution 

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder(TreeNode* A, vector<long long>& v, long long n)
{
    if(A == NULL) return;
    else if(A->left == NULL && A->right == NULL)
    {
        n = (n*10 + (1ll)*(A->val))%1003;
        v.push_back(n);
        return;
    }
    n = (n*10 + (1ll)*(A->val))%1003;
    inorder(A->left, v, n);
    inorder(A->right, v, n);
}
int Solution::sumNumbers(TreeNode* A) {
    vector<long long> v;
    long long n =0;
    inorder(A, v, n);
    long long ans = 0;
    for(int i=0; i<v.size(); i++)
    {
        ans = (ans + v[i]%1003)%1003;
    }
    return ans;
    
}
