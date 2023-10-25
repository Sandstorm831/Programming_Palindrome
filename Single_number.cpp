// Question Link - https://leetcode.com/problems/single-number/description/?envType=study-plan-v2&envId=top-interview-150
// Solution 

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        for(int i=0; i<nums.size(); i++) x^=nums[i];
        return x;
    }
};