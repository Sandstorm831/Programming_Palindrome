# Leetcode solution
# Link : https://leetcode.com/problems/binary-tree-inorder-traversal/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def recursor(root, inorder):
    if root == None:
        return
    recursor(root.left, inorder)
    inorder.append(root.val)
    recursor(root.right, inorder)

class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        inorder = []
        recursor(root, inorder)
        return inorder
