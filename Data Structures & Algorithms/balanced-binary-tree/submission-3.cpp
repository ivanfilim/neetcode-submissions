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
    bool balanced = true;

    int height(TreeNode* root) {
        if (root == nullptr || balanced == false) {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (balanced) {
            balanced = leftHeight - rightHeight >= -1 && leftHeight - rightHeight <= 1;
        }
        return 1 + max(leftHeight, rightHeight);
    }
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        balanced = true;
        height(root);
        return balanced;
    }
};