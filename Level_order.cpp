#include <bits/stdc++.h>
using namespace std;
/*
Problem Description

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

Input Format
First and only argument is root node of the binary tree, A.

Output Format
Return a 2D integer array denoting the zigzag level order traversal of the given binary tree.
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int>> store;
    queue<TreeNode*> q;
    q.push(A);
    q.push(NULL);
    vector<int> temp;
    while(!q.empty())
    {
        while(!q.front() == NULL)
        {
            TreeNode* idx = q.front();
            temp.push_back(idx->val);
            q.pop();
            if(idx->left != NULL) q.push(idx->left);
            if(idx->right != NULL) q.push(idx->right);
        }
        q.pop();
        store.push_back(temp);
        temp.clear();
        if(!q.empty()) q.push(NULL);
    }
    return store;
}