// Question link  - https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/
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
TreeNode* builder(const vector<int> &A, int ini, int fin)
{
    if(ini > fin) return NULL;
    int mid = (ini + fin)/2;
    TreeNode* n = new TreeNode(A[mid]);
    if(ini == fin) return n;
    n->left = builder(A, ini, mid-1);
    n->right = builder(A, mid+1, fin);
    return n;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    if(A.size()==0) return NULL;
    if(A.size()==1)
    {
        return new TreeNode(A[0]);
    }
    TreeNode* head = builder(A, 0, A.size()-1);
    return head;
}
