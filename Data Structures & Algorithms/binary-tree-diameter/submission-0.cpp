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
    int d = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 0;
        }
        int leftHeight = (root->left != nullptr ? 1 : 0) + binaryTreeHeight(root->left);
        int rightHeight = (root->right != nullptr ? 1 : 0) + binaryTreeHeight(root->right);
        return max(d, leftHeight + rightHeight);
    }

    int binaryTreeHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 0;
        }

        int leftHeightTrimmed = binaryTreeHeight(root->left);
        int rightHeightTrimmed = binaryTreeHeight(root->right);

        d = max(d, leftHeightTrimmed + rightHeightTrimmed + (root->left != nullptr ? 1 : 0) + (root->right != nullptr ? 1 : 0));

        return max(1 + leftHeightTrimmed, 1 + rightHeightTrimmed);
    }
};
