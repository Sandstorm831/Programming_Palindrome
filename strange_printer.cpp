// Question Link - https://leetcode.com/problems/strange-printer/description/
// solution 

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, n));
        for(int length = 1; length<=n; length++)
        {
            for(int left = 0; left<=n-length; left++)
            {
                int right = left+length-1;
                int diff = -1;
                for(int i=left; i<right; i++)
                {
                    if(s[i] != s[right] && diff == -1)
                    {
                        diff = i;
                    }
                    if(diff != -1)
                    {
                        dp[left][right] = min(dp[left][right], 1+dp[diff][i]+dp[i+1][right]);
                    }
                }
                if(diff == -1) dp[left][right] = 0;
            }
        }
        return dp[0][n-1]+1;
    }
};
// Explanation - https://leetcode.com/problems/strange-printer/editorial