# Leetcode solution
# Link : https://leetcode.com/problems/binary-tree-level-order-traversal/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        q = deque()
        q.append(root)
        q.append(None)
        levels = []
        temp = []
        while len(q) > 0:
            a = q.popleft()
            if a == None:
                if len(temp) > 0:
                    levels.append(temp)
                    temp = []
                    q.append(None)
            else:
                temp.append(a.val)
                if a.left:
                    q.append(a.left)
                if a.right:
                    q.append(a.right)
        return levels
