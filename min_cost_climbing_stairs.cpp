// Question Link - https://leetcode.com/problems/min-cost-climbing-stairs/description?envType=study-plan-v2&envId=dynamic-programming
// Solution 

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, 0);
        dp[1] = 0, dp[2] = min(cost[0],cost[1]);
        for(int i=3; i<=cost.size(); i++)
        {
            dp[i] = min(cost[i-1]+dp[i-1], cost[i-2]+dp[i-2]);
        }
        return dp[cost.size()];
    }
};