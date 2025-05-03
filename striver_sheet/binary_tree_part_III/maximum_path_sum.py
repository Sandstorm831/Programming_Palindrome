# Leetcode solution
# Link : https://leetcode.com/problems/binary-tree-maximum-path-sum/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def recursor(root, store):
    if root == None:
        return 0
    l = recursor(root.left, store)
    r = recursor(root.right, store)
    store[0] = max(store[0], max(l,0)+max(r,0)+root.val)
    x = max(0,max(l,r)) + root.val
    return x

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        maxIntree = [-1001]
        br = recursor(root, maxIntree)
        return max(br, maxIntree[0])
