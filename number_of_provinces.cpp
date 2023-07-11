// Question Link - https://leetcode.com/problems/number-of-provinces/description/?envType=study-plan-v2&envId=graph-theory
// Solution

class Solution {
public:
    void bfs(vector<vector<int>>& graph, vector<int>& vis,int node)
    {
        vis[node]=true;
        queue<int> q;
        q.push(node);
        while(!q.empty())
        {
            int nod = q.front();
            q.pop();
            for(int i=0; i<graph.size(); i++)
            {
                if(graph[nod][i]==1 && !vis[i])
                {
                    vis[i]=true;
                    q.push(i);
                }
            }
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, false);
        int counter=0;
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                counter++;
                bfs(isConnected, vis, i);
            }
        }
        return counter;
    }
};