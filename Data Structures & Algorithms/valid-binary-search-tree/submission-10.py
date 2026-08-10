# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def nodeValid(self, node: Optional[TreeNode], upperBound: int, lowerBound: int) -> bool:
        if not node:
            return True
        if (upperBound is not None and node.val >= upperBound) or (lowerBound is not None and node.val <= lowerBound):
            return False
        return self.nodeValid(node.left, node.val, lowerBound) and self.nodeValid(node.right, upperBound, node.val)

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.nodeValid(root, None, None)