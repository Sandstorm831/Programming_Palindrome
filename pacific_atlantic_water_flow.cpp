////// Question LInk - https://leetcode.com/problems/pacific-atlantic-water-flow/description?envType=study-plan-v2&envId=graph-theory
// solution 

class Solution {
public:
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};
    bool checker(int x, int y, int n, int m)
    {
        if(x>=0 && y>=0 && x<n && y<m) return true;
        return false;
    }
    void bfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& vis)
    {
        if(vis[x][y]) return;
        vis[x][y]=true;
        queue<pair<int,int>> q;
        q.push(make_pair(x,y));
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int xx = p.first+dx[i];
                int yy = p.second+dy[i];
                if(checker(xx,yy,grid.size(), grid[0].size()) && !vis[xx][yy] && grid[xx][yy]>=grid[p.first][p.second])
                {
                    q.push(make_pair(xx,yy));
                    vis[xx][yy]=true;
                }
            }
        }
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        vector<vector<bool>> pacific(heights.size(), vector<bool> (heights[0].size(), false));
        vector<vector<bool>> atlantic(heights.size(), vector<bool> (heights[0].size(), false));
        for(int i=0; i<heights.size();i++)
        {
            if(!pacific[i][0]) bfs(i,0,heights, pacific);
        }
        for(int j=0;j<heights[0].size(); j++)
        {
            if(!pacific[0][j]) bfs(0,j,heights,pacific);
        }
        for(int i=0;i<heights.size();i++)
        {
            if(!atlantic[i][heights[0].size()-1]) bfs(i,heights[0].size()-1,heights,atlantic);
        }
        for(int j=0;j<heights[0].size();j++)
        {
            if(!atlantic[heights.size()-1][j]) bfs(heights.size()-1, j, heights, atlantic);
        }
        for(int i=0;i<heights.size();i++)
        {
            for(int j=0;j<heights[0].size();j++)
            {
                if(pacific[i][j] && atlantic[i][j]) res.push_back({i,j});
                // if(i == 4 && j==0) cout<<pacific[i][j]<<" "<<atlantic[i][j]<<endl;
            }
        }
        return res;
    }
};