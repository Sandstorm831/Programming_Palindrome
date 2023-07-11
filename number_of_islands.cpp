// Question Link - https://leetcode.com/problems/number-of-islands/description?envType=study-plan-v2&envId=graph-theory
// Solution 

class Solution {
public:
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};
    bool checker(int x, int y, int n, int m)
    {
        if(x>=0 && y>=0 && x<n && y<m) return true;
        return false;
    }
    void bfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& vis)
    {
        if(vis[x][y]) return;
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
                if(checker(xx,yy,grid.size(), grid[0].size()) && !vis[xx][yy] && grid[xx][yy]=='1')
                {
                    q.push(make_pair(xx,yy));
                    vis[xx][yy]=true;
                }
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> vis(grid.size()+1, vector<bool> (grid[0].size()+1,false));
        int counter=0;
        for(int i=0; i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size(); j++)
            {
                if(grid[i][j] == '1' && !vis[i][j]) 
                {
                    counter++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return counter;
    }
};