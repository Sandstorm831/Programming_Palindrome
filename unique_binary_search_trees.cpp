// Question Link - https://leetcode.com/problems/unique-binary-search-trees/description/?envType=study-plan-v2&envId=dynamic-programming
// solution 

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(20,0);
        dp[0]=1, dp[1]=1, dp[2]=2;
        for(int i=3; i<20; i++)
        {
            int ans = 0;
            for(int j=1; j<=i; j++)
            {
                int l = j-1;
                int r = i-j;
                ans += dp[l]*dp[r];
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};