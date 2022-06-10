/* Problem Link - https://www.interviewbit.com/problems/kth-smallest-element-in-tree/
 * Problem Solution Function ---------------------------------------------------------+
 * Definition for binary tree                                                         |  
 * struct TreeNode {                                                                  |  
 *     int val;                                                                       |  
 *     TreeNode *left;                                                                |          
 *     TreeNode *right;                                                               |
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}                           |  
 * };                                                                                 |  
 *                                                                                    |  
void inordertraversal(TreeNode* head, int& count, int target, int& picker){     <-----+
    if(head == NULL) return;
    inordertraversal(head->left, count, target, picker);
    count++;
    if(count == target) picker = head->val;
    inordertraversal(head->right, count, target, picker);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    int count =0;
    int picker;
    inordertraversal(A, count, B, picker);
    return picker;
}
*/