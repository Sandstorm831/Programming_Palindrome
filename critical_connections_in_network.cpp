//Question Link - https://leetcode.com/problems/critical-connections-in-a-network/description/
// Solution 

class Solution {
public:
    int timer=1;
    void dfs(int node, int parent, vector<vector<int>>& graph, vector<bool>& vis, vector<int>& curr, vector<int>& low, vector<vector<int>>& impedges)
    {
        vis[node]=true;
        curr[node] = low[node]=timer;
        timer++;
        for(int i=0; i<graph[node].size();i++)
        {
            if(graph[node][i] == parent) continue;
            else if(!vis[graph[node][i]])
            {
                dfs(graph[node][i], node, graph, vis, curr, low, impedges);
                low[node] = min(low[node], low[graph[node][i]]);
                if(curr[node]<low[graph[node][i]])
                {
                    impedges.push_back({node, graph[node][i]});
                }
            }
            else
            {
                low[node] = min(low[node], low[graph[node][i]]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n, vector<int> ());
        for(int i=0; i<connections.size();i++)
        {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool> vis(n,false);
        vector<int> curr(n), low(n);
        vector<vector<int>> impedges;
        dfs(0, -1, graph, vis, curr, low, impedges);
        return impedges;
    }
};

// For understanding https://youtu.be/qrAub5z8FeA