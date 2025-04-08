# Leetcode solution
# link : https://leetcode.com/problems/longest-consecutive-sequence/
#

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        x = {}
        maxer = 1
        for i in range(len(nums)):
            x[nums[i]] = 1
        for i in x:
            if i-1 not in x:
                print(i)
                temp = 0
                curr = i
                while curr in x:
                    curr += 1
                    temp+=1
                maxer = max(maxer, temp)
        return maxer
