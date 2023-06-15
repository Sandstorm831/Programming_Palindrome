// Question LInk - https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/
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
int finder(vector<int>& inorder, int i,int  j,int value)
{
    for(auto k =i; k<=j; ++k)
    {
        if(inorder[k] == value) return k;
    }   
}
TreeNode* preandinordertotree(vector<int>& inorder, vector<int>& preorder, int i, int j, int& preo)
{
    if(i>j) return NULL;
    TreeNode* head = new TreeNode(preorder[preo]);
    preo--;
    if(i == j) return head;
    int partioner = finder(inorder, i,j, head->val);
    head->right = preandinordertotree(inorder, preorder, partioner+1, j, preo);
    head->left = preandinordertotree(inorder, preorder, i, partioner-1, preo);
    return head;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    if(A.size() == 0|| B.size() == 0) return NULL;
    int preo = B.size()-1;
    return preandinordertotree(A,B,0,A.size()-1, preo);
}