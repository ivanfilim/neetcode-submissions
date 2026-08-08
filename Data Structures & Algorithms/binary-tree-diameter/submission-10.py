# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        maxDepthLeft = (1 if root.left else 0) + self.maxDepth(root.left)
        maxDepthRight = (1 if root.right else 0) + self.maxDepth(root.right)
        diameterThroughRoot = maxDepthLeft + maxDepthRight
        self.diameter = max(self.diameter, diameterThroughRoot)
        return max(maxDepthLeft, maxDepthRight)
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.diameter = 0
        self.maxDepth(root)
        return self.diameter

        