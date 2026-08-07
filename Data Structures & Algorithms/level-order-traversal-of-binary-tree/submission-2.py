# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def registerLevel(self, levels, currLevel, root):
        if not root:
            return
        if len(levels) == currLevel:
            levels.append([])
        levels[currLevel].append(root.val)
        self.registerLevel(levels, currLevel + 1, root.left)
        self.registerLevel(levels, currLevel + 1, root.right)
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        levels = []
        self.registerLevel(levels, 0, root)
        return levels
