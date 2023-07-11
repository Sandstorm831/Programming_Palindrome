// Question LInk - https://leetcode.com/problems/house-robber/description/?envType=study-plan-v2&envId=dynamic-programming
// Solution 

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> robs(nums.size()+1, 0);
        robs[0] = nums[0];
        if(nums.size()==1) return robs[0];
        robs[1] = max(nums[0], nums[1]);
        for(int i=2; i<nums.size(); i++)
        {
            robs[i] = max(nums[i]+robs[i-2], robs[i-1]);
        }
        return robs[nums.size()-1];
    }
};