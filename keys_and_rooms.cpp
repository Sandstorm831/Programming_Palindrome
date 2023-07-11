// Question Link - https://leetcode.com/problems/keys-and-rooms/description/
// Solution 

class Solution {
public:
    void bfs(vector<vector<int>> & graph, vector<int>& vis, int node)
    {
        queue<int> q;
        q.push(node);
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            vis[x]=true;
            for(int i=0; i<graph[x].size(); i++)
            {
                if(!vis[graph[x][i]])
                {
                    q.push(graph[x][i]);
                }
            }
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n =rooms.size();
        vector<int> vis(n, false);
        bfs(rooms, vis, 0);
        for(int i=0; i<n; i++)
        {
            // cout<<vis[i]<<" ";
            if(!vis[i]) return false;
        }
        return true;
    }
};