// Question Link - https://leetcode.com/problems/minimum-size-subarray-sum/description/
// solution

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minn = INT_MAX;
        int summ = 0;
        int j=0;
        while(summ < target && j<nums.size()) 
        {
            summ+=nums[j];
            j++;
        }
        int i = 0;
        while(summ >= target && i<=j && i<nums.size())
        {
            minn = min(minn, j-i);
            summ-=nums[i];i++;
            while(summ < target && j<nums.size())
            {
                summ+=nums[j];j++;
            }
        }
        if(minn == INT_MAX) return 0;
        return minn;
    }
};