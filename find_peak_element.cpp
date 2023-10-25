// Question Link - https://leetcode.com/problems/find-peak-element/description/?envType=study-plan-v2&envId=top-interview-150
// solution 

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        else if(nums[0] > nums[1]) return 0;
        else if(nums[nums.size()-1] > nums[nums.size()-2])  return nums.size()-1;
        else
        {
            int l = 0, r = nums.size()-1;
            while(l<r)
            {
                int mid = (l+r+1)/2;
                if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
                else if(nums[mid] < nums[mid-1]) r = mid-1;
                else if(nums[mid] < nums[mid+1]) l=mid;
            }
            return l;
        }
    }
};