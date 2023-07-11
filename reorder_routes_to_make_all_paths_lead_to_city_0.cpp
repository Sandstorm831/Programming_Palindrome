// Question Link - https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/
//Solution 

class Solution {
public:
    void dfs(vector<vector<pair<int,int>>> &graph, vector<bool> &vis, int node, int& counter)
    {
        if(vis[node]) return;
        vis[node]=true;
        for(int i=0; i<graph[node].size(); i++)
        {
            if(!vis[graph[node][i].first])
            {
                dfs(graph, vis, graph[node][i].first, counter);
                if(graph[node][i].second == 1) counter++;
            }
        }
        return;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> graph(n, vector<pair<int,int>> ());
        for(int i=0;i<connections.size();i++)
        {
            graph[connections[i][0]].push_back(make_pair(connections[i][1], 1));
            graph[connections[i][1]].push_back(make_pair(connections[i][0], 0));
        }
        int counter=0;
        vector<bool> vis(n, false);
        dfs(graph, vis, 0, counter);
        return counter;
    }
};