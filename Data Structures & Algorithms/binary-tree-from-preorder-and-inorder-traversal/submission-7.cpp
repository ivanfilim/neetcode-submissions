class Solution {
public:
    unordered_map<int, int> indexMap;

    TreeNode* build(
        vector<int>& preorder,
        int preorderLeft,
        int preorderRight,
        int inorderLeft,
        int inorderRight
    ) {
        if (preorderLeft > preorderRight) {
            return nullptr;
        }

        int rootValue = preorder[preorderLeft];
        TreeNode* root = new TreeNode(rootValue);

        int inorderRoot = indexMap[rootValue];
        int leftSize = inorderRoot - inorderLeft;

        root->left = build(
            preorder,
            preorderLeft + 1,
            preorderLeft + leftSize,
            inorderLeft,
            inorderRoot - 1
        );

        root->right = build(
            preorder,
            preorderLeft + leftSize + 1,
            preorderRight,
            inorderRoot + 1,
            inorderRight
        );

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            indexMap[inorder[i]] = i;
        }

        return build(
            preorder,
            0,
            preorder.size() - 1,
            0,
            inorder.size() - 1
        );
    }
};