# leetcode solution
# link : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def treebuilder(nums, ii, ff):
    # print(ii,ff)
    if ii == ff:
        return TreeNode(val = nums[ii])
    elif ii > ff:
        return None
    mid = ii + (ff-ii)//2
    root = TreeNode(val = nums[mid])
    root.left = treebuilder(nums, ii, mid-1)
    root.right = treebuilder(nums, mid+1, ff)
    return root

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        return treebuilder(nums, 0, len(nums)-1)
