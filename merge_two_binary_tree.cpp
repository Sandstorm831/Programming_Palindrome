// Question Link - https://www.interviewbit.com/problems/merge-two-binary-tree/
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
void inorder(TreeNode** A, TreeNode* B)
{
    TreeNode* head = *A;
    if(B != NULL) head->val = head->val + B->val;
    else if(B==NULL) return ;
    if(B->left != NULL)
    {
        if(head->left == NULL)
        {
            TreeNode* x = new TreeNode(0);
            inorder(&x, B->left);
            head->left = x;
        }
        else
        {
            inorder(&head->left, B->left);
        }
    }
    if(B->right != NULL)
    {
        if(head->right == NULL)
        {
            TreeNode* x = new TreeNode(0);
            inorder(&x, B->right);
            head->right = x;
        }
        else
        {
            inorder(&head->right, B->right);
        }
    }
}
TreeNode* Solution::solve(TreeNode* A, TreeNode* B) {
    TreeNode* head = new TreeNode(0);
    inorder(&head, A);
    inorder(&head, B);
    return head;
}
