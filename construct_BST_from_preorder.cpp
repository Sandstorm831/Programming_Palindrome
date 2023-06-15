// Question Link - https://www.interviewbit.com/problems/construct-bst-from-preorder/
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
unordered_map<int,int> ino;
int finder(vector<int>& inorder, int i,int  j,int value)
{
    return ino[value];
}
TreeNode* preandinordertotree(vector<int>& inorder, vector<int>& preorder, int i, int j, int& preo)
{
    if(i>j) return NULL;
    TreeNode* head = new TreeNode(preorder[preo]);
    preo++;
    if(i == j) return head;
    int partioner = finder(inorder, i,j, head->val);
    head->left = preandinordertotree(inorder, preorder, i, partioner-1, preo);
    head->right = preandinordertotree(inorder, preorder, partioner+1, j, preo);
    return head;
}
TreeNode* Solution::constructBST(vector<int> &A) {
    ino.clear();
    vector<int> B = A;
    sort(B.begin(), B.end());
    for(int i=0; i<B.size(); i++) ino[B[i]]=i;
    if(A.size() == 0|| B.size() == 0) return NULL;
    int preo = 0;
    return preandinordertotree(B,A,0,A.size()-1, preo);
}
