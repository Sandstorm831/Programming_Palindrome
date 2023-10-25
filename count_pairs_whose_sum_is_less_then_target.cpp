// Question Link -https://leetcode.com/contest/biweekly-contest-111/problems/count-pairs-whose-sum-is-less-than-target/
// Solution

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int counter=0;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                if(nums[i]+nums[j] < target) counter++;
            }   
        }
        return counter;
    }
};