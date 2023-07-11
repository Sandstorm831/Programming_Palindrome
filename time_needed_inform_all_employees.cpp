// Question LInk - https://leetcode.com/problems/time-needed-to-inform-all-employees/description/
// solution 

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>graph (n,vector<int> ());
        for(int i=0; i<n; i++)
        {
            if(manager[i]!=-1)
            {
                graph[i].push_back(manager[i]);
                graph[manager[i]].push_back(i);
            }
        }
        queue<pair<int,int>> q;
        q.push(make_pair(headID, 0));
        vector<bool> vis(n, false);
        int maxx=INT_MIN;
        while(!q.empty())
        {
            pair<int,int> x = q.front();
            q.pop();
            vis[x.first]=true;
            maxx = max(x.second+informTime[x.first], maxx);
            for(int i=0; i<graph[x.first].size(); i++)
            {
                if(!vis[graph[x.first][i]])
                {
                    q.push(make_pair(graph[x.first][i], informTime[x.first]+x.second));
                }
            }
            
        }
        return maxx;
    }
};