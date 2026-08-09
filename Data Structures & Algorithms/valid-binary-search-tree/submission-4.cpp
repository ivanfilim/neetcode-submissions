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
    bool nodeValid(TreeNode* node, int min, int max, bool leftSet, bool rightSet) {
        if (!node) return true;
        if ((node->val >= min && leftSet) || (node->val <= max && rightSet)) return false;
        return nodeValid(node->left, node->val, max, true, rightSet) && nodeValid(node->right, min, node->val, leftSet, true);
    }
public:
    bool isValidBST(TreeNode* root) {
        return nodeValid(root, root->val, root->val, false, false);
    }
};
