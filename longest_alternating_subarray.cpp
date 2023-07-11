// Question LInk - https://leetcode.com/contest/biweekly-contest-108/problems/longest-alternating-subarray/
// Solution 

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int i=0;
        int n = nums.size();
        while(i+1<n && nums[i]+1 != nums[i+1]) i++;
        if(i+1>=nums.size()) return -1;
        int ans = 2;
        int a=nums[i], b=nums[i+1];
        int maxx=2;
        i = i+2;
        for(; i<nums.size(); i++)
        {
            if(nums[i] == nums[i-2]) 
            {
                ans++; maxx=max(maxx, ans);
            }
            else
            {
                while(i<nums.size() && nums[i-1]+1 != nums[i])i++;
                if(i>=nums.size()) break;
                ans = 2;
                a=nums[i-1];
                b=nums[i];
            }
        }
        return maxx;
    }
};