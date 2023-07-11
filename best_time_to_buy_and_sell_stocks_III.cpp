// Question Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/?envType=study-plan-v2&envId=dynamic-programming
// solution

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 2;
        vector<vector<int>> dp(k+1, vector<int> (prices.size()+1, 0));
        for(int i=1; i<=k; i++)
        {
            int temp = INT_MIN;
            for(int j=2; j<=prices.size(); j++)
            {
                temp = max(temp, dp[i-1][j-1]-prices[j-2]);
                dp[i][j] = max(dp[i][j-1], temp+prices[j-1]);
            }
        }
        return dp[k][prices.size()];
    }
};