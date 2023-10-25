// Question Link - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
// Solution 

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int x = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int y = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(x >= nums.size() || nums[x] != target) return {-1,-1};
        else return {x, y-1};
    }
};