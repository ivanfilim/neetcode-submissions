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
    bool nodeValid(TreeNode* node, int leftBound, int rightBound) {
        if (!node) return true;
        if (node->val <= leftBound || node->val >= rightBound) {
            return false;
        }
        return nodeValid(node->left, leftBound, node->val) && nodeValid(node->right, node->val, rightBound);
    }
public:
    bool isValidBST(TreeNode* root) {
        return nodeValid(root, numeric_limits<int>::min(), numeric_limits<int>::max());
    }
};
