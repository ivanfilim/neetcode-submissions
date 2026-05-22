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

    int binaryTreeHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftHeight = binaryTreeHeight(root->left);
        int rightHeight = binaryTreeHeight(root->right);
        d = max(d, leftHeight + rightHeight);

        return max(leftHeight, rightHeight) + 1;
    }

    int diameterForRoot(int leftHeight, int rightHeight, TreeNode* root) {
        return 
            (root->left != nullptr ? 1 : 0) + 
            leftHeight + 
            (root->right != nullptr ? 1 : 0) + 
            rightHeight;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        d = 0;
        int leftHeight = binaryTreeHeight(root);
        return d;
    }
};