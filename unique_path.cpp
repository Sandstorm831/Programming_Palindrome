// Question LInk - https://leetcode.com/problems/unique-paths/description?envType=study-plan-v2&envId=dynamic-programming
// Solution 

class Solution {
public:
    vector<vector<int>> dp;
    int recursor(int m, int n, int x, int y)
    {
        if(x == m-1 || y == n-1) return 1;
        else if(dp[x][y] != -1) return dp[x][y];
        return dp[x][y] = recursor(m,n,x+1, y)+recursor(m, n, x,y+1);
    }
    int uniquePaths(int m, int n) {
        dp.clear();
        dp.resize(m, vector<int> (n, -1));
        return recursor(m,n,0,0);
    }
};