// Question Link - https://www.interviewbit.com/problems/remove-half-nodes/
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
void solver(TreeNode* head, TreeNode* prev, int dir)
{
    if(head == NULL) return ;
    else if(head->left != NULL && head->right ==NULL) 
    {
        solver(head->left, prev, dir);
    }
    else if(head->left == NULL && head->right != NULL)
    {
        solver(head->right, prev, dir);
    }
    else
    {
        if(dir == 1) prev->right = head;
        else if(dir == -1) prev->left = head;
        solver(head->left, head, -1);
        solver(head->right, head, 1);
    }
    return ;
}
TreeNode* Solution::solve(TreeNode* A) {
    if(A==NULL) return A;
    TreeNode* head = A;
    while((head != NULL) && ((head->left != NULL && head->right == NULL) || (head->left == NULL && head->right != NULL)))
    {
        if(head->left != NULL) head = head->left;
        else head = head->right;
    }
    if(head == NULL) return head;
    else if(head->left == NULL && head->right == NULL) return head;
    else if(head->left != NULL && head->right != NULL) 
    {
        solver(head->left, head, -1);
        solver(head->right, head, 1);
    }
    return head;
}