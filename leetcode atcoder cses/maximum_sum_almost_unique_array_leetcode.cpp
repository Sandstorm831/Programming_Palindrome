// Question Link - https://leetcode.com/contest/biweekly-contest-112/problems/maximum-sum-of-almost-unique-subarray/
// solution 

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<long long,long long> ump;
        long long i=0,summ=0, maxer = LLONG_MIN;
        for(;i<k;i++) {ump[nums[i]]++;summ+=nums[i];}
        while(i<nums.size())
        {
            if(ump.size()>=m) maxer = max(maxer, summ);
            ump[nums[i-k]]--;
            if(ump[nums[i-k]] == 0) ump.erase(nums[i-k]);
            summ-=(nums[i-k]);
            ump[nums[i]]++;
            summ+=nums[i];
            i++;
        }
        if(ump.size()>=m) maxer = max(maxer, summ);
        return max(1ll*0,maxer);
        
    }
};