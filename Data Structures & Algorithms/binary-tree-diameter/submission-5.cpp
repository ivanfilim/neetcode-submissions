/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int maxDepth(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int diameterThroughRoot = (root->left ? 1 : 0) + maxDepth(root->left) + (root->right ? 1 : 0) + maxDepth(root->right);
        int maxBetweenLeftAndRight = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
        return max(diameterThroughRoot, maxBetweenLeftAndRight);
    }
};
