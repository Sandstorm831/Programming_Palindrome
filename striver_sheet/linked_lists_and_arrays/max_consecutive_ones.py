# Leetcode solution
# Link : https://leetcode.com/problems/max-consecutive-ones/

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        maxer = 0
        curr = 0
        for i in range(len(nums)):
            if nums[i] == 1:
                curr += 1
                maxer = max(maxer, curr)
            else:
                curr = 0
        return maxer
