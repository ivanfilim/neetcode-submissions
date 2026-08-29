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
    map<int, int> m;
public:
    TreeNode* buildTree(vector<int>& p, vector<int>& i) {
        if (p.empty()) return nullptr;
        for (int j = 0; j < static_cast<int>(i.size()); ++j) {
            m[i[j]] = j;
        }
        return buildTree(p, 0, i.size() - 1);

    }

private:
    TreeNode* buildTree(vector<int>& p, int left, int right) {
        if (p.empty()) return nullptr;
        auto root = new TreeNode(p[0]);
        int lsize = m[p[0]] - left;
        vector<int> pleft(p.begin() + 1, p.begin() + lsize + 1);
        int rsize = right - m[p[0]];
        vector<int> pright(p.end() - rsize, p.end());
        root->left = buildTree(pleft, left, m[p[0]] - 1);
        root->right = buildTree(pright, m[p[0]] + 1, right );
        return root;
    }    
};