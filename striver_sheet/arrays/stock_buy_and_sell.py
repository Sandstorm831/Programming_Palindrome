# Leetcode Solution 
# Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxer = prices[-1]
        res = 0
        for i in range(len(prices)-1, -1, -1):
            maxer = max(prices[i], maxer)
            res = max(maxer - prices[i], res)
        return res
