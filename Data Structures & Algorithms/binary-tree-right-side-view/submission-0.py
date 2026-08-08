# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def registerLevel(self, levels: List[int], curr_level: int, root: Optional[TreeNode]):
        if not root:
            return
        if len(levels) == curr_level:
            levels.append(root.val)
        else:
            levels[curr_level] = root.val;
        self.registerLevel(levels, curr_level + 1, root.left)
        self.registerLevel(levels, curr_level + 1, root.right)
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        right_side_view = []
        self.registerLevel(right_side_view, 0, root)
        return right_side_view