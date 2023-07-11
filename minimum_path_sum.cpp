// Question Link - https://leetcode.com/problems/minimum-path-sum/description?envType=study-plan-v2&envId=dynamic-programming
// solution 

class Solution {
public:
    vector<vector<int>> dp;
    bool checker(int x,int y,int n,int m)
    {
        if(x>=0 && y>=0 && x<n && y<m) return true;
        return false;
    }
    int recursor(vector<vector<int>>& grid, int x,int y, int n, int m)
    {
        if(x == n-1 && y == m-1) return grid[n-1][m-1];
        else if(dp[x][y] != -1) return dp[x][y]; 
        else 
        {
            int ans=INT_MAX;
            if(checker(x+1, y, n, m))
            {
                ans = recursor(grid, x+1, y, n, m) + grid[x][y];
            }
            if(checker(x, y+1, n, m))
            {
                ans = min(recursor(grid, x, y+1, n, m)+grid[x][y], ans);
            }
            return dp[x][y] = ans;
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        dp.clear();dp.resize(grid.size(), vector<int> (grid[0].size(), -1));
        return recursor(grid, 0, 0, grid.size(), grid[0].size());
    }
};