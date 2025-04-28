# Leetcode solution
# Link : https://leetcode.com/problems/permutations

def recursor(nums, index, temp, ans):
    if index >= len(nums):
        ans.append(temp[:])
        return
    for i in range(len(nums)):
        if nums[i] > 10:
            continue
        x = nums[i]
        nums[i] = 11
        temp.append(x)
        recursor(nums, index+1, temp, ans)
        temp.pop()
        nums[i] = x

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        temp = []
        index = 0
        ans = []
        recursor(nums, index, temp, ans)
        return ans
