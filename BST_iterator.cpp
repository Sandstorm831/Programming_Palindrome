// Problem Link - https://www.interviewbit.com/problems/bst-iterator/submissions/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
stack<TreeNode*> A;
void inordertraversal(TreeNode* head){
    while(head != NULL)
    {
        A.push(head);
        head = head->left;
    }
    return;
}

BSTIterator::BSTIterator(TreeNode *root) {
    inordertraversal(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !A.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode* cr = A.top(); A.pop();
    if(cr->right != NULL) inordertraversal(cr->right);
    return cr->val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
**/