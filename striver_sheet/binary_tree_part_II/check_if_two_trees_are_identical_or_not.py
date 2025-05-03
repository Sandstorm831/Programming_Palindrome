# Leetcode solution
# Link : https://leetcode.com/problems/same-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def recursor(rootp, rootq):
    if rootp == None and rootq == None:
        return True
    elif (rootp == None and rootq != None ) or (rootp != None and rootq == None):
        return False
    elif rootp.val != rootq.val:
        return False
    x = recursor(rootp.left, rootq.left)
    if not x:
        return False
    x = recursor(rootp.right, rootq.right)
    if not x:
        return False
    return True

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        x = recursor(p, q)
        return x
