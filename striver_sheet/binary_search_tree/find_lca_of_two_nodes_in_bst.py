# Leetcode solution
# Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
def recursor(root, l, h):
    if root.val > l.val and root.val < h.val:
        return root
    elif root.val > h.val:
        return recursor(root.left, l, h)
    elif root.val < l.val:
        return recursor(root.right, l, h)
    elif root.val == h.val or root.val == l.val:
        return root

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if p.val < q.val:
            return recursor(root, p, q)
        else:
            return recursor(root, q, p)
