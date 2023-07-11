// Question Link- https://leetcode.com/problems/remove-element/description?envType=study-plan-v2&envId=top-interview-150
// solution

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int counter=0;
        for(int j=0, i=0; j<nums.size(); i++, j++)
        {
            if(nums[j] == val) i--;
            else
            {
                nums[i] = nums[j];
                counter++;
            }
        }
        return counter;
    }
};