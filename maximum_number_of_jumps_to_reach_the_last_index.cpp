// Question Link - https://leetcode.com/contest/weekly-contest-353/problems/maximum-number-of-jumps-to-reach-the-last-index/
// solution 

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(),-1);
        dp[0]=0;
        for(int i=1; i<nums.size(); i++)
        {
            int maxx = -1;
            for(int j=i-1; j>=0; j--)
            {
                if(dp[j] != -1 && abs(nums[j]-nums[i])<=target) maxx = max(maxx, 1+dp[j]);
            }
            dp[i] = maxx;
        }
        return dp[nums.size()-1];
    }
};