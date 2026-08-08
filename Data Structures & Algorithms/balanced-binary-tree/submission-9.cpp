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
        if (heightLeft == -1) return -1;
        int heightRight = height(root->right);
        if (heightRight == -1) return -1;
        if (abs(heightRight - heightLeft) > 1) {
            return -1;
        }
        return max(heightLeft, heightRight) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
