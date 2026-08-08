# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def visitNode(self, node: TreeNode, maxBefore: int):
        if not node:
            return
        if maxBefore <= node.val:
            self.goodNodesNum += 1
            maxBefore = node.val
        self.visitNode(node.left, maxBefore)
        self.visitNode(node.right, maxBefore)
    def goodNodes(self, root: TreeNode) -> int:
        self.goodNodesNum = 0
        self.visitNode(root, root.val)
        return self.goodNodesNum