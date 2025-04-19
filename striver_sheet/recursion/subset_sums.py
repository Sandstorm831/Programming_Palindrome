# GFG Solution
# Link : https://www.geeksforgeeks.org/problems/subset-sums2234/1

def recursor(nums,holder, summer, index):
  if index >= len(nums):
    holder.append(summer)
    return
  else:
    recursor(nums, holder, summer, index+1)
    recursor(nums, holder, summer+nums[index], index+1)


#User function Template for python3
class Solution:
    def subsetSums(self, arr):
        holder = []
        recursor(arr, holder, 0, 0)
        return holder
