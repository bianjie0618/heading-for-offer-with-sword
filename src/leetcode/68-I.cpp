// 剑指 Offer 68 - I. 二叉搜索树的最近公共祖先

// Definition for a binary tree node.
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // 二叉搜索树
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }
        
        if (p == root || q == root || p->val < root->val && q->val > root->val || p->val > root->val && q->val < root->val) {
            return root;
        }

        if (p->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};