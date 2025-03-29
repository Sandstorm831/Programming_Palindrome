# Leetcode solution
# Link : https://leetcode.com/problems/majority-element/

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        holder = nums[0]
        freq = 1
        for i in range(1, len(nums)):
            temp = nums[i]
            if nums[i] == holder :
                freq+=1
            elif nums[i] != holder:
                freq -= 1
            if freq == 0:
                holder = temp
                freq = 1
        return holder
            