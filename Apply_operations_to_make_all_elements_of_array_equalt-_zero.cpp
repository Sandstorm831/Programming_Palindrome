// Question Link - https://leetcode.com/contest/weekly-contest-353/problems/apply-operations-to-make-all-array-elements-equal-to-zero/
// Solution 

class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        vector<int> sub(nums.size()+k+1, 0);
        int subt=0;
        for(int i=0; i<nums.size(); i++)
        {
            subt -= sub[i];
            if(nums[i]>subt) 
            {
                int x = nums[i]-subt;
                if(i+k<=nums.size()) 
                {
                    sub[i+k] += x;
                    subt = nums[i];
                }
            }
            nums[i] -= subt;
        }
        for(int i=0; i<nums.size(); i++) if(nums[i] != 0) return false;
        return true;

    }
};