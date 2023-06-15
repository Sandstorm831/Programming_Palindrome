// Question Link - https://www.interviewbit.com/problems/nodes-at-distance-k/
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
int N = 1e5+5;
vector<vector<int>> graph;
vector<int> vis;
void inorder(TreeNode* A)
{
    if(A==NULL) return;
    if(A->left != NULL) 
    {
        graph[A->val].push_back(A->left->val); 
        graph[A->left->val].push_back(A->val); 
    }
    if(A->right != NULL) 
    {
        graph[A->val].push_back(A->right->val);
        graph[A->right->val].push_back(A->val);
    }
    inorder(A->left);inorder(A->right); 
}
vector<int> Solution::distanceK(TreeNode* A, int B, int C) {
    graph.clear();
    vis.clear();
    vis.resize(N, false);
    graph.resize(N, vector<int> ());
    inorder(A);
    int nod = B;
    queue<int> q;
    q.push(B);
    q.push(INT_MAX);
    while(C>0)
    {
        int nod = q.front();
        q.pop();
        if(nod == INT_MAX)
        {
            C--;
            q.push(INT_MAX);
            continue;
        }
        vis[nod]=true;
        for(int i=0; i<graph[nod].size(); i++)
        {
            if(!vis[graph[nod][i]])
            {
                q.push(graph[nod][i]);
            }
        }
    }
    vector<int> ans;
    while(!q.empty())
    {
        ans.push_back(q.front());
        q.pop();
    }
    ans.pop_back();
    return ans;
}
  

///////// 
// Approach without using graphs
// Traverse every node with a depth first search dfs. 
// We'll add all nodes x to the answer such that node is the node on the path from x to target that is closest to the root.
// 
// To help us, dfs(node) will return the distance from node to the target. Then, there are 4 cases:
// 
// 1) If node == B, then we should add nodes that are distance C in the subtree rooted at target.
// 2) If target is in the left branch of node, say at distance L+1, 
//    then we should look for nodes that are distance C - L - 1 in the right branch.
// 3) If target is in the right branch of node, the algorithm proceeds similarly.
// 4) If target isn't in either branch of node, then we stop.
// 
// In the above algorithm, we make use of the auxillary function subtree_add(node, dist) 
// which adds the nodes in the subtree rooted at node that are distance C - dist from the given node.


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
map<TreeNode*, TreeNode*> parent;
TreeNode* target;
vector<int> ans;
void dfs(TreeNode* root, int B){
    if(root->val==B){
        target = root;
    }
    if(root->left!=NULL){
        parent[root->left] = root;
        dfs(root->left, B);
    }
    if(root->right!=NULL){
        parent[root->right] = root;
        dfs(root->right, B);
    }
}

void bfs(int C){
    
    map<TreeNode*, int> depth;
    queue<TreeNode*> q;
    q.push(target);
    depth[target] = 0;
    
    while(!q.empty()){
        TreeNode* cur = q.front();
        q.pop();
        
        if(parent.find(cur)!=parent.end()){
            TreeNode* t = parent[cur];
            if(depth.find(t)==depth.end() || depth[t]>1+depth[cur]){
                depth[t] = 1+depth[cur];
                if(depth[t]==C){
                    ans.push_back(t->val);
                }
                q.push(t);
            }
        }
        
        if(cur->left!=NULL){
            TreeNode* t = cur->left;
            if(depth.find(t)==depth.end() || depth[t]>1+depth[cur]){
                depth[t] = 1+depth[cur];
                if(depth[t]==C){
                    ans.push_back(t->val);
                }
                q.push(t);
            }
        }
        
        if(cur->right!=NULL){
            TreeNode* t = cur->right;
            if(depth.find(t)==depth.end() || depth[t]>1+depth[cur]){
                depth[t] = 1+depth[cur];
                if(depth[t]==C){
                    ans.push_back(t->val);
                }
                q.push(t);
            }
        }
    }
}

vector<int> Solution::distanceK(TreeNode* A, int B, int C) {
    parent.clear();
    ans.clear();
    dfs(A, B);
    bfs(C);
    return ans;
}