// Question Link - https://leetcode.com/problems/all-paths-from-source-to-target/description/
// Solution 

class Solution {
public:
    void dfs(vector<vector<int>>& graph, int node, vector<vector<int>>& ans, vector<int>& temp)
    {
        if(node==graph.size()-1)
        {
            temp.push_back(node);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(node);
        for(int i=0; i<graph[node].size();i++)
        {
            dfs(graph, graph[node][i], ans, temp);
        }
        temp.pop_back();
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(graph, 0, ans, temp);
        return ans;
    }
};