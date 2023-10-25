// question Link - https://leetcode.com/problems/search-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
// Solution 

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums[0]<nums.back())
        {
            int x = lower_bound(nums.begin(), nums.end(), target)-nums.begin();
            if(x >= nums.size()) return -1;
            else if(nums[x] != target) return -1;
            else return x;
        }
        int l = 0, r = nums.size()-1;
        cout<<"here"<<endl;
        while(l<r)
        {
            int mid = (l+r+1)/2;
            if(nums[mid] > nums[0] && nums[mid+1] < nums[0]) break;
            else if(nums[mid] > nums[0]) l = mid;
            else if(nums[mid] < nums[0]) r = mid-1;
        }
        int p = (l+r+1)/2;
        if(target>=nums[0] && target <= nums[p])
        {
            int x = lower_bound(nums.begin(), nums.begin()+p, target)-nums.begin();
            if(x > p) return -1;
            else if(nums[x] != target) return -1;
            else return x;
        }
        else
        {
            int x = lower_bound(nums.begin()+p+1, nums.end(), target)-nums.begin();
            if( x >= nums.size()) return -1;
            else if(nums[x] != target) return -1;
            else return x;
        }
    }
};