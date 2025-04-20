# Leetcode solution
# Link : https://leetcode.com/problems/combination-sum-ii/

def recursor(nums, ans, temp, target, index):
    if target < 0:
        return
    elif target == 0:
        ans.append(temp[:])
        return
    elif index >= len(nums):
        return
    elif nums[index] > target:
        return
    for i in range(index, len(nums)):
        if i != index and nums[i] == nums[i-1]:
            continue
        temp.append(nums[i])
        recursor(nums, ans, temp, target-nums[i], i+1)
        temp.pop()



class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        x = []
        temp = []
        recursor(candidates, x, temp, target, 0)
        return x
