// Question Link - https://leetcode.com/problems/unique-paths-ii/description/?envType=study-plan-v2&envId=dynamic-programming
// solution

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<long long>> dp(obstacleGrid.size(), vector<long long> (obstacleGrid[0].size(), 0));
        long long n = obstacleGrid.size();
        long long m = obstacleGrid[0].size();
        for(long long i=n-1; i>=0; i--)
        {
            for(long long j=m-1; j>=0; j--)
            {
                if(i==n-1 && j==m-1 && obstacleGrid[i][j] == 0) dp[i][j] = 1;
                else if(i == n-1 && obstacleGrid[i][j] == 0) dp[i][j] += dp[i][j+1];
                else if(j == m-1 && obstacleGrid[i][j] == 0) dp[i][j] += dp[i+1][j];
                else if( obstacleGrid[i][j] == 0)
                {
                    dp[i][j] += dp[i+1][j] + dp[i][j+1];
                }
            }
        }
        return dp[0][0];
    }
};