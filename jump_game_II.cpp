// Question Link - https://leetcode.com/problems/jump-game-ii/description?envType=study-plan-v2&envId=top-interview-150
// Solution 

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int reachable = nums[0];
        int jumps=1;
        int max_reachable=-1;
        for(int i=1; i<nums.size();i++)
        {
            if(i == nums.size()-1) return jumps;
            else if(i == reachable)
            {
                jumps++;
                if(i+nums[i] > reachable) max_reachable = max(max_reachable, i+nums[i]);
                reachable = max_reachable;
                max_reachable = -1;
            }
            else if(i < reachable)
            {
                if(i+nums[i]>reachable) max_reachable = max(max_reachable, i+nums[i]);
            }
        }
        return jumps;
    }
};