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
    int diameter = 0;

    int maxDepth(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return 0;
        int maxDepthLeft = maxDepth(root->left), maxDepthRight = maxDepth(root->right);
        int diameterThroughRoot = (root->left ? 1 : 0) + maxDepthLeft + (root->right ? 1 : 0) + maxDepthRight;
        diameter = max(diameter, diameterThroughRoot);
        return max(maxDepthLeft, maxDepthRight) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return diameter;
    }
};
