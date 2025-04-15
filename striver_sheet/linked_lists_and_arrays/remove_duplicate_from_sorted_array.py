# Leetcode solution
# Link : https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        curr_p = 0
        forward_p = 1
        while forward_p < len(nums):
            while curr_p != forward_p and nums[curr_p] == nums[forward_p]:
                forward_p+=1
                if forward_p >= len(nums):
                    break
            if forward_p < len(nums):
                curr_p+=1
                nums[curr_p] = nums[forward_p]
                if curr_p == forward_p:
                    forward_p += 1
        curr_p += 1
        nums[:] = nums[:curr_p]
