# Leetcode Solution 
# Link : https://takeuforward.org/data-structure/find-the-duplicate-in-an-array-of-n1-integers/
# hare and tortoise algorithm : https://keithschwarz.com/interesting/code/?dir=find-duplicate

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        rab = 0
        tor = 0
        while True:
            rab = nums[nums[rab]]
            tor = nums[tor]
            if rab == tor:
                break
        p1 = 0
        while True:
            p1 = nums[p1]
            tor = nums[tor]
            if p1 == tor:
                return tor
        