// Question Link - https://leetcode.com/problems/rotate-array/description/
// Solution 

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k == 0) return;
        int carry = nums[0];
        int x = nums.size();
        int j = 0;
        int start=0;
        while(x)
        {
            do
            {
                j = (j+k)%nums.size();
                int temp = nums[j];
                nums[j] = carry;
                carry = temp;
                x--;
            }while(j != start);
            start++;
            j = start;
            carry = nums[j];
        }
    }
};