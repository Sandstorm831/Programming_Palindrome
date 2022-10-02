/* Problem Link - https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

A height balanced BST : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example :


Given A : 1 -> 2 -> 3
A height balanced BST  :

      2
    /   \
   1     3
*/
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* treeformer(TreeNode* base, vector<int>& sorter, int ini, int fin)
{
    if(ini>fin) return NULL;
    int il = (ini+fin)/2;
    base = new TreeNode(sorter[il]);
    base->left = treeformer(base->left, sorter, ini, il-1);
    base->right = treeformer(base->right, sorter, il+1, fin);
    return base;
}
TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> sorter;
    ListNode* x = A;
    while(x != NULL)
    {
        sorter.push_back(x->val);
        x = x->next;
    }
    int siz = sorter.size();
    int fin = siz-1;
    TreeNode* base;
    return treeformer(base, sorter,0, fin);
}