// Question Link - https://leetcode.com/contest/weekly-contest-351/problems/ways-to-split-array-into-good-subarrays/
// Solution

class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int mod = 1e9+7;
        vector<long long> v;
        long long counter=-1;
        for(int i=0; i<nums.size();i++)
        {
            if(nums[i]==1 && counter!=-1)
            {
                v.push_back(counter+1*1ll);
                counter=0;
            }
            else if(nums[i]==1) counter=0;
            else if(nums[i]==0 && counter != -1) counter++;
        }
        if(v.size()==0 && counter==-1) return 0;
        long long ans=1;
        for(int i=0;i<v.size();i++)
        {
            ans = (ans%mod * v[i]%mod)%mod;
        }
        return ans;
    }
};