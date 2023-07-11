// Question LInk - https://leetcode.com/problems/minimum-cost-for-tickets/description/?envType=study-plan-v2&envId=dynamic-programming
// Solution 

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        sort(days.begin(), days.end());
        vector<int> dp(days.size()+1, 0);
        for(int i=1; i<=days.size(); i++)
        {
            int l = upper_bound(days.begin(), days.end(), days[i-1]-7)-days.begin()-1;
            int lt = upper_bound(days.begin(), days.end(), days[i-1]-30)-days.begin()-1;
            dp[i] = min(costs[0]+dp[i-1], min(costs[1]+dp[l+1], costs[2]+dp[lt+1]));
        }
        return dp[days.size()];
    }
};