# Leetcode solution
# Link : https://leetcode.com/problems/subsets-ii/

def recursor(nums, x, index, holder):
    if index >= len(nums):
        if holder not in x:
            x.append(holder[:])
        return
    else:
        recursor(nums, x, index+1, holder)
        holder.append(nums[index]);
        recursor(nums, x, index+1, holder)
        holder.pop()
        return

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort();
        x = []
        a = []
        recursor(nums, x, 0, a)
        return x
