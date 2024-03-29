// Question LInk - https://leetcode.com/problems/maximal-square/description/
// Solution 

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxx = INT_MIN;
        vector<vector<int>> dp(n, vector<int> (m,0));
        for(int i=0;i<n; i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j]-'0';
                    maxx = max(maxx, dp[i][j]);
                }
                else if(matrix[i][j]=='1') 
                {
                    dp[i][j] = 1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
                    maxx = max(maxx, dp[i][j]);
                }
            }
        }
        return maxx*maxx;
    }
};
// For explanation https://leetcode.com/problems/maximal-square/solutions/600149/python-thinking-process-diagrams-dp-approach/