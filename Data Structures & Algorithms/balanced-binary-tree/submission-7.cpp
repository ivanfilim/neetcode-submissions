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
        if (!root) return 0;
        int heightLeft = height(root->left);
        int heightRight = height(root->right);
        if (abs(heightRight - heightLeft) > 1) {
            balanced = false;
        }
        return max(heightLeft, heightRight) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        height(root);
        return balanced;
    }
};
