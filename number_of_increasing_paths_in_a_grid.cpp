// Question Link - https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/description/
// Solution 

class Solution {
public:
    int mod = 1e9+7;
    vector<int> dx = {1,0, -1, 0};
    vector<int> dy = {0,1,0, -1};
    int checker(int x, int y, int n, int m)
    {
        if(x>=0 && x<n && y>=0 && y<m) return true;
        return false;
    }
    int recursor(vector<vector<int>>& grid,  vector<vector<int>>& dp, int x, int y)
    {
        // if(vis[x][y]) return 0;
        // vis[x][y] = true;
        int ans = 0;
        if(dp[x][y] != -1) return dp[x][y]%mod;
        for(int i=0; i<4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(checker(xx, yy, grid.size(), grid[0].size()) && grid[xx][yy]>grid[x][y])
            {
                // cout<<x<<" () "<<y<<" () "<<xx<<" () "<<yy<<endl;
                ans = (ans%mod + recursor(grid, dp, xx, yy)%mod)%mod;
                // vis[xx][yy]=true;
            }
        }
        return dp[x][y] = ans+1;
    }
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size()+1, vector<int> (grid[0].size()+1, -1));
        // vector<vector<bool>> vis(grid.size()+1, vector<bool> (grid[0].size()+1, false));
        int ans = 0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                dp[i][j] = (recursor(grid,  dp, i, j)%mod);
                ans = (ans%mod + dp[i][j]%mod)%mod;
                // cout<<i<<" || "<<j<<" || "<<ans<<endl;
                // vis.clear();
                // vis.resize(grid.size()+1, vector<bool> (grid[0].size()+1, false));
            }
        }
        return ans;
    }
};