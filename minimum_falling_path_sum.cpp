// Question Link - https://leetcode.com/problems/minimum-falling-path-sum/description/?envType=study-plan-v2&envId=dynamic-programming
// Solution 

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int> (matrix[0].size(),0));
        int n = matrix.size();
        int m = matrix[0].size();
        int ans;
        for(int i=n-1;i>=0; i--)
        {
            int minn = INT_MAX;
            for(int j=m-1; j>=0; j--)
            {
                if(i==n-1)
                {
                    dp[i][j] = matrix[i][j];
                    minn = min(dp[i][j],minn);
                }
                else if(j == 0)
                {
                    dp[i][j] = matrix[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
                    minn = min(dp[i][j],minn);
                }
                else if(j==m-1)
                {
                    dp[i][j] = matrix[i][j]+min(dp[i+1][j-1],dp[i+1][j]);
                    minn = min(dp[i][j],minn);
                }
                else 
                {
                    dp[i][j] = matrix[i][j] + min(min(dp[i+1][j-1],dp[i+1][j]),dp[i+1][j+1]);
                    minn = min(dp[i][j],minn);
                }
            }
            ans = minn;
        }
        return ans;
    }
};