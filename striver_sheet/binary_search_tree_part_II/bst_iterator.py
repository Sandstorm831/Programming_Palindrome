# Leetcode solution
# Link : https://leetcode.com/problems/binary-search-tree-iterator/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:
    def __init__(self, root: Optional[TreeNode]):
        self.st = []
        self.pushAll(root)

    def next(self) -> int:
        x = self.st.pop()
        self.pushAll(x.right)
        return x.val

    def hasNext(self) -> bool:
        x = len(self.st)
        if x > 0:
            return True
        return False

    def pushAll(self, root) -> None:
        while root != None:
            self.st.append(root)
            root = root.left


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
