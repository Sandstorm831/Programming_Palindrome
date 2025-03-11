# Leetcode Solution 
# Link : https://leetcode.com/problems/next-permutation/

########## Important Comment ##################
# We want to find a larger number, but not too large - just the next larger one =>
# We want to avoid chaning the number in the left - it will increase the number too much =>
# Example: 4325413 -> we can only change the last two numbers and have 432531
# What if it was 432531 in the first place? 31 cannot be increased.
# Lets try 531 - still no
# 2531 - this can be incrased - the smallest number that can be used to incrase the 2 is 3. so for now we have 3521.
# Next we want to minimize 3521 - thats easier - just sort the numbers to the right of 3 - 3125. So the unswer is 4323125
##############################################

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        x = []
        reg_index = -1
        for i in range(len(nums)-1, -1, -1):
            x.append(nums[i])
            if(len(x) > 1 and x[-1] < x[-2]):
                reg_index = i
                break
        if(reg_index == -1):
            nums.sort()
            x = [0]
            return
        anchor = x[-1]
        x.sort()
        next_anchor = -1
        for i in range(len(x)):
            if x[i] > anchor:
                next_anchor = x[i]
                x.pop(i)
                break
        nums[reg_index] = next_anchor
        reg_index+=1
        in_index = 0
        for i in range(reg_index, len(nums)):
            nums[i] = x[in_index]
            in_index+=1
        