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
    void registerLevel(vector<vector<int>> &levels, int currLevel, TreeNode* root) {
        if (!root) return;
        if (static_cast<int>(levels.size()) < currLevel + 1) {
            levels.push_back(vector<int>());
        }
        levels[currLevel].push_back(root->val);
        registerLevel(levels, currLevel + 1, root->left);
        registerLevel(levels, currLevel + 1, root->right);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        registerLevel(res, 0, root);
        return res;
    }
};
