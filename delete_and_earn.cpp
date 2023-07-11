// Question LInk - https://leetcode.com/problems/delete-and-earn/solutions/3705307/delete-and-earn/
// Solution

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int,int> mp;
        int minn = INT_MAX;
        int maxx = INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            minn = min(minn, nums[i]);maxx = max(maxx, nums[i]);
            if(mp.find(nums[i]) == mp.end()) mp[nums[i]]=nums[i];
            else mp[nums[i]]+= nums[i];
        }
        vector<vector<int>> dp(maxx+1, vector<int> (2,0));
        dp[minn][0] = 0; dp[minn][1] = mp[minn];
        for(int i=minn+1; i<=maxx; i++)
        {
            if(mp.find(i) == mp.end())
            {
                dp[i][0]=dp[i-1][0];
                dp[i][1]=dp[i-1][1];
                continue;
            }
            if(i-1>=minn)
            {
                dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
            }
            if(i-2>=minn)
            {
                dp[i][1] = mp[i]+max(dp[i-2][1], dp[i-2][0]);
            }
            else dp[i][1] = mp[i];
        }
        return max(dp[maxx][0], dp[maxx][1]);
    }
};