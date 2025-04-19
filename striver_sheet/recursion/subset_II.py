# Leetcode solution
# Link : https://leetcode.com/problems/subsets-ii/

# more optimal as we don't have to check for uniqueness, it is based in the algorithm
def recursor(nums, x, index, holder):
    x.append(holder[:])
    for i in range(index, len(nums)):
        if i != index and nums[i] == nums[i-1]:
            continue
        holder.append(nums[i])
        recursor(nums, x, i+1, holder)
        holder.pop()

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort();
        x = []
        a = []
        recursor(nums, x, 0, a)
        return x

# Less optimal
# def recursor(nums, x, index, holder):
#     if index >= len(nums):
#         if holder not in x:
#             x.append(holder[:])
#         return
#     else:
#         recursor(nums, x, index+1, holder)
#         holder.append(nums[index]);
#         recursor(nums, x, index+1, holder)
#         holder.pop()
#         return

# class Solution:
#     def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
#         nums.sort();
#         x = []
#         a = []
#         recursor(nums, x, 0, a)
#         return x
