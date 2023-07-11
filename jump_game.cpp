// Question Link - https://leetcode.com/problems/jump-game/description?envType=study-plan-v2&envId=top-interview-150
// Solution 

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        else if(nums[0]==0) return false;
        int counter=nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            counter--;
            counter = max(counter, nums[i]);
            if(counter == 0 && i < nums.size()-1 && i) return false;
            else if(counter == 0 && i == nums.size()-1) return true;
        }
        return true;
    }
};