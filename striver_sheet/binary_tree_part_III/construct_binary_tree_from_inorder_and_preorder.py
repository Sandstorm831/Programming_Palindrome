# Leetcode solution
# Link : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def treemaker(preorder, inorder, mapper,ip, fp, ii, fi):
    # print(">", ip, fp, ii, fi)
    if ip > fp or ii > fi:
        return None
    # print(preorder[ip])
    root = TreeNode(val = preorder[ip])
    tid = mapper[preorder[ip]]
    num = tid - ii
    # print(num, preorder[ip], ip, tid, "--")
    root.left = treemaker(preorder, inorder, mapper, ip+1, ip + num, ii, tid-1)
    root.right = treemaker(preorder, inorder, mapper, ip+num+1, fp, tid+1, fi)
    return root

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        mapper = {}
        for i in range(len(inorder)):
            mapper[inorder[i]] = i

        return treemaker(preorder, inorder, mapper, 0, len(preorder)-1, 0, len(inorder)-1)
