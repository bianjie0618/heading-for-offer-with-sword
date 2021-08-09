// 剑指 Offer 68 - II. 二叉树的最近公共祖先

// Definition for a binary tree node.

// 逻辑牛逼透了
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) {
            return root;
        }
        TreeNode* leftRes = nullptr;
        TreeNode* rightRes = nullptr;
        if (root->left != nullptr) {
            leftRes = lowestCommonAncestor(root->left, p, q);
        }
        if (root->right) {
            rightRes = lowestCommonAncestor(root->right, p, q);
        }

        if (leftRes != nullptr && rightRes != nullptr) {
            return root;
        }
        else {
            return leftRes != nullptr ? leftRes : rightRes;
        }
    }
};