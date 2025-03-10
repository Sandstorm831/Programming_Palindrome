# Leetcode Solution 
# Link : https://leetcode.com/problems/sort-colors/
# Dutch National Flag algorithm

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l, m, h = 0, 0, len(nums)-1
        while h>=m:
            if nums[m] == 0:
                nums[l], nums[m] = nums[m], nums[l]
                l+=1
                m+=1
            elif nums[m] == 1:
                m += 1
            elif nums[m] == 2:
                nums[m], nums[h] = nums[h], nums[m]
                h-=1

            
# Ad-hoc solution

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        zeros = 0
        ones = 0
        twos = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                zeros+=1
            elif nums[i] == 1:
                ones += 1
            else:
                twos+=1
        for i in range(len(nums)):
            if zeros>0:
                nums[i] = 0
                zeros-=1
            elif ones>0:
                nums[i] = 1
                ones-=1
            else:
                nums[i] = 2
                twos-=1

            
        