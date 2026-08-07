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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int rootVal = root->val, pVal = p->val, qVal = q->val;
        if (pVal < rootVal && qVal < rootVal) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (pVal > rootVal && qVal > rootVal) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
};
