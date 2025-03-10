# Leetcode Solution 
# Link : https://leetcode.com/problems/maximum-subarray/
# Kadane's Algorithm 

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_ending = nums[0]
        res = nums[0]
        for i in range(1, len(nums)):
            max_ending = max(max_ending+nums[i], nums[i])
            res = max(res, max_ending)
        return res