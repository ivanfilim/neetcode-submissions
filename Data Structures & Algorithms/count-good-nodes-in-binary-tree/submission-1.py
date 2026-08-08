# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def visitNode(self, node: TreeNode, maxBefore: int):
        if not node:
            return 0
        increment = 0
        if maxBefore <= node.val:
            increment += 1
            maxBefore = node.val
        return increment + self.visitNode(node.left, maxBefore) + self.visitNode(node.right, maxBefore)
    def goodNodes(self, root: TreeNode) -> int:
        return self.visitNode(root, root.val)