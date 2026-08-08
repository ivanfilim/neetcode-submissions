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
    void dfs(vector<int>& rightSideView, int currLevel, TreeNode* root) {
        if (!root) return;
        if (static_cast<int>(rightSideView.size()) == currLevel) {
            rightSideView.push_back(root->val);
        } else {
            rightSideView[currLevel] = root->val;
        }
        dfs(rightSideView, currLevel + 1, root->left);
        dfs(rightSideView, currLevel + 1, root->right);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightSideView;
        dfs(rightSideView, 0, root);
        return rightSideView;
    }
};
