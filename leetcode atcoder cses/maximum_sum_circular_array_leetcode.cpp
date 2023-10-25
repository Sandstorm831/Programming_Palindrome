// Question LInk - https://leetcode.com/problems/maximum-sum-circular-subarray/description/
// solution 

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = 0, curra = 0, currb=0, miner = 0, maxx=INT_MIN, maxer=INT_MIN;
        for(int i=0; i<nums.size();i++)
        {
            curra += nums[i]; currb+=nums[i];
            total_sum += nums[i];
            maxer = max(maxer, currb);
            if(currb < 0) currb=0;
            maxx = max(maxx, nums[i]);
            miner = min(miner, curra);
            if(curra > 0) curra = 0;
        }
        if(total_sum - miner != 0)return max(total_sum - miner, maxer);
        return maxer;
    }
};