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
        if (!root) return 0;
        int maxDepthLeft = (root->left ? 1 : 0) + maxDepth(root->left);
        int maxDepthRight = (root->right ? 1 : 0) + maxDepth(root->right);
        int diameterThroughRoot = maxDepthLeft + maxDepthRight;
        diameter = max(diameter, diameterThroughRoot);
        return max(maxDepthLeft, maxDepthRight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return diameter;
    }
};
