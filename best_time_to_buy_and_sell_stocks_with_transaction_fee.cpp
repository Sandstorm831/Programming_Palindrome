// Question LInk - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description
// Solution 

class Solution {
public: 
    int maxProfit(vector<int>& prices, int fee) {
        int zer = -prices[0];
        int profit = 0;
        for(int i=1;i<prices.size();i++)
        {
            zer = max(zer,profit-prices[i-1]);
            profit = max(profit, prices[i]-fee+zer);
        }
        return profit;
    }
};