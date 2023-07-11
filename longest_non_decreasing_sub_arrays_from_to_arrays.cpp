// Question Link - https://leetcode.com/contest/weekly-contest-353/problems/longest-non-decreasing-subarray-from-two-arrays/
// Solution 

class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int> (2, 1));
        dp[0][0]=1;
        dp[0][1]=1;
        int maxx = 1;
        for(int i=1; i<nums1.size(); i++)
        {
            if(nums1[i]>=nums1[i-1]) dp[i][0] = dp[i-1][0]+1;
            if(nums1[i]>=nums2[i-1]) dp[i][0] = max(dp[i][0], dp[i-1][1]+1);
            if(nums2[i]>=nums2[i-1]) dp[i][1] = dp[i-1][1]+1;
            if(nums2[i]>=nums1[i-1]) dp[i][1] = max(dp[i][1], dp[i-1][0]+1);
            maxx = max(maxx, max(dp[i][0], dp[i][1]));
        }
        return maxx;
    }
};