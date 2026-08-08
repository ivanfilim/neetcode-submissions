# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def height(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        left = self.height(root.left)
        if left == -1:
            return -1
        right = self.height(root.right)
        if right == -1:
            return -1
        if abs(left - right) > 1:
            return -1
        return max(left, right) + 1
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.height(root) != -1