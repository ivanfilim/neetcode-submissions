# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def sameTree(self, first: Optional[TreeNode], second: Optional[TreeNode]):
        if not first or not second:
            return first == second
        if first.val != second.val:
            return False
        return self.sameTree(first.left, second.left) and self.sameTree(first.right, second.right)
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not subRoot:
            return True
        if not root:
            return root == subRoot
        return self.sameTree(root, subRoot) or self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)