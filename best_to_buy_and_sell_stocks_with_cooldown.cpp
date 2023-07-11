// Question Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/?envType=study-plan-v2&envId=dynamic-programming
// Solution 

class Solution {
public:
    vector<vector<int>> dp;
    int recursor(vector<int>& prices, int node, int status)
    {
        if(node >= prices.size()) return 0;
        if(node == prices.size()-1)
        {
            if(status) return prices[node];
            else return 0;
        }
        else if(dp[status][node] !=-1) return dp[status][node];
        else
        {
            int ans = 0;
            if(!status)
            {
                ans = max(ans,max(recursor(prices, node+1, 1)-prices[node], recursor(prices, node+1, 0)));
            }
            else
            {
                ans = max(ans,max(recursor(prices, node+2, 0)+prices[node], recursor(prices, node+1, 1)));
            }
            return dp[status][node] = ans;
        }
    }
    int maxProfit(vector<int>& prices) {
        dp.clear();dp.resize(2, vector<int> (prices.size()+1, -1));
        if(prices.size()<=1) return 0;
        return recursor(prices, 0, 0);
    }
};