// Question Link - https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-interview-150
// Solution 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long zeros=0;
        long long index=0;
        vector<int> ans(nums.size(),0);
        for(long long i=0; i<nums.size();i++) if(nums[i]==0) index=i,zeros++;
        if(zeros>1) return ans;
        else if(zeros == 1)
        {
            long long prod = 1;
            for(long long i=0; i<nums.size(); i++)
            {
                if(i == index) continue;
                prod *= nums[i];
            }
            ans[index] = prod;
            return ans;
        }
        else
        {
            long long prod=1;
            for(long long i=0; i<nums.size();i++) prod *= nums[i];
            for(long long i=0; i<nums.size();i++)
            {
                ans[i] = prod/nums[i];
            }
            return ans;
        }
    }
};