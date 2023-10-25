// Question Link - https://leetcode.com/problems/wiggle-subsequence/description/
// Solution 

class Solution {
public:
    vector<vector<int>> dp;
    int recursor(vector<int>& nums, int fin, int diff)
    {
        if(fin == 1)
        {
            if((diff == 0 && nums[fin-1] != nums[fin]) || (diff ==1 && nums[fin-1] < nums[fin]) || (diff == 2 && nums[fin-1] > nums[fin])) return 2;
            else return 1;
        }
        else if(dp[fin][diff] != -1) return dp[fin][diff];
        else 
        {
            int maxx = INT_MIN;
            for(int i=fin-1; i>=0; i--)
            {
                if(diff == 0)
                {
                    if(nums[i] < nums[fin]) maxx = max(maxx, 1+recursor(nums, i, 2));
                    else if(nums[i] > nums[fin]) maxx = max(maxx, 1+recursor(nums, i, 1));
                }
                else if(diff == 1)
                {
                    if(nums[i] < nums[fin]) maxx = max(maxx, 1+recursor(nums, i, 2));
                }
                else if(diff == 2)
                {
                    if(nums[i] > nums[fin]) maxx = max(maxx, 1+recursor(nums, i, 1));
                }
            }
            return dp[fin][diff] = maxx;
        }
    }
    int wiggleMMaxLength(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        else if(nums.size() == 2 && nums[0] != nums[1]) return 2;
        else if(nums.size() == 2) return 1;
        dp.clear();
        dp.resize(nums.size()+1, vector<int> (3, -1));
        int counter=INT_MIN;
        for(int i=1; i<nums.size(); i++) {counter = max(counter,recursor(nums, i, 0));}
        return counter;
    }


// Another approach

    // This solution is inspired by the fact, you have to total number of peaks and valleys in the array
    int wiggleMaxLength(vector<int>& nums) {
        int size=nums.size(), peak=1, valley=1;
        for(int i=1; i<size; ++i)
        {
            if(nums[i]>nums[i-1]) peak = valley + 1;
            else if(nums[i]<nums[i-1]) valley = peak + 1;
        }
        return max(peak , valley );
    }
};