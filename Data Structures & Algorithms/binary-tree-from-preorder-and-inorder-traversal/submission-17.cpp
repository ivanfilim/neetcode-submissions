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
    vector<int> preorder;
    map<int, int> inorderIndexMap;

    TreeNode* build(int preLeft, int preRight, int inLeft, int inRight) {
        if (preLeft > preRight) return nullptr;

        int rootValue = preorder[preLeft];
        int inorderRootIdx = inorderIndexMap[rootValue];
        
        int leftSize = inorderRootIdx - inLeft;

        auto root = new TreeNode(rootValue);
        root->left = build(
            preLeft + 1, preLeft + leftSize,
            inLeft, inorderRootIdx - 1
        );
        root->right = build(
            preLeft + leftSize + 1, preRight,
            inorderRootIdx + 1, inRight
        );
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        this->preorder = preorder;
        for (int i = 0; i < inorder.size(); ++i) inorderIndexMap[inorder[i]] = i;
        return build(
            0, preorder.size() - 1,
            0, inorder.size() - 1
        );
    }
};
