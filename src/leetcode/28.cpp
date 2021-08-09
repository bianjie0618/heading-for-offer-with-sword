// 剑指 Offer 28. 对称的二叉树

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }
        return dfs(root->left, root->right);
    }

    bool dfs(TreeNode* left, TreeNode* right) {
        if (left != nullptr && right != nullptr && left->val == right->val) {
            return dfs(left->left, right->right) && dfs(left->right, right->left);
        }
        else if(left == nullptr && right == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }
};