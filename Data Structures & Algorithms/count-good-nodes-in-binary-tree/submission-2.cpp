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
    int visitNode(TreeNode* node, int maxBefore) {
        if (!node) return 0;
        int inc = 0;
        if (node->val >= maxBefore) {
            inc = 1;
            maxBefore = node->val;
        }
        return inc + visitNode(node->left, maxBefore) + visitNode(node->right, maxBefore);
    }
public:
    int goodNodes(TreeNode* root) {
        return visitNode(root, root->val);
    }
};
