// Question Link - https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/
// Solution 

class Solution {
public:
    int dfs(int node, string& colors, vector<vector<int>>& graph, vector<vector<int>>& dp, vector<int>& jus)
    {
        if(!jus[node])
        {
            jus[node]=1;
            for(int j=0;j<graph[node].size(); j++)
            {
                if(dfs(graph[node][j], colors, graph, dp, jus) == INT_MAX) return INT_MAX;
                for(int i=0; i<26; i++) dp[node][i] = max(dp[node][i], dp[graph[node][j]][i]);
            }
            dp[node][colors[node]-'a']++;
            jus[node]=2;
        }
        return jus[node]==2?dp[node][colors[node]-'a']:INT_MAX;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<vector<int>> graph(colors.size());
        vector<vector<int>> dp(colors.size(), vector<int> (26));
        vector<int> jus(colors.size());
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        int res=0;
        for(int i=0; i<colors.size() && res!=INT_MAX;i++) res = max(dfs(i,colors, graph,dp, jus), res);
        return res==INT_MAX?-1:res;
    }
};