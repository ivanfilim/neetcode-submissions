# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if len(preorder) == 0:
            return None
        inorderIdxMap = {}
        for i in range(len(inorder)):
            inorderIdxMap[inorder[i]] = i
        def build(preStart, preEnd, inStart, inEnd):
            if preStart > preEnd:
                return None
            rootVal = preorder[preStart]
            root = TreeNode(rootVal)
            rootInorderIdx = inorderIdxMap[rootVal]
            leftLength = rootInorderIdx - inStart
            root.left = build(preStart + 1, preStart + leftLength, inStart, rootInorderIdx - 1)
            root.right = build(preStart + leftLength + 1, preEnd, rootInorderIdx + 1, inEnd)
            return root
        return build(0, len(preorder) - 1, 0, len(inorder) - 1)