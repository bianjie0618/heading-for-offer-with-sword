// 剑指 Offer 55 - I. 二叉树的深度

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }

    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + max(dfs(node->left), dfs(node->right));
    }
};