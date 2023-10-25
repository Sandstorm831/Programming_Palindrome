// Question Link - https://leetcode.com/problems/maximum-subarray/description/?envType=study-plan-v2&envId=top-interview-150
// solution 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxer = INT_MIN;
        int curr = 0;
        int maxx = INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            curr += nums[i];
            maxx = max(maxx, nums[i]);
            if(curr < 0) curr = 0;
            else maxer = max(maxer, curr);
        }
        return max(maxx, maxer);
    }
};