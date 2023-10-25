// question LInk - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
// solution 

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.back() > nums[0] || nums.size()==1) return nums[0];
        int l = 0, r = nums.size()-1;
        while(l<r)
        {
            int mid = (l+r+1)/2;
            if(nums[mid] > nums[0] && nums[mid+1] < nums[0]) break;
            else if(nums[mid] > nums[0]) l = mid;
            else if(nums[mid] < nums[0]) r = mid-1;
        }
        return nums[(l+r+1)/2 + 1];
    }
};