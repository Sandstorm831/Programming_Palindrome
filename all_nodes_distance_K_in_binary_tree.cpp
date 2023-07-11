// Question Link - https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
// solution 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recursor(vector<vector<int>>& graph,TreeNode* root){
        if(root == NULL) return;
        if(root->left != NULL)
        {
            graph[root->left->val].push_back(root->val);
            graph[root->val].push_back(root->left->val);
            recursor(graph, root->left);
        }
        if(root->right != NULL)
        {
            graph[root->right->val].push_back(root->val);
            graph[root->val].push_back(root->right->val);
            recursor(graph, root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<vector<int>> graph(501, vector<int> ());
        recursor(graph, root);
        vector<int> ans;
        queue<pair<int,int>> q;
        q.push(make_pair(target->val,0));
        vector<bool> vis(501,false);
        vis[target->val]=true;
        while(!q.empty())
        {
            pair<int,int> x = q.front();
            q.pop();
            if(x.second == k)
            {
                ans.push_back(x.first);
                continue;
            }
            for(int i=0; i<graph[x.first].size(); i++)
            {
                if(!vis[graph[x.first][i]])
                {
                    q.push(make_pair(graph[x.first][i], x.second+1));
                    vis[graph[x.first][i]]=true;
                }
            }
        }
        return ans;
    }
};