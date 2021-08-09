// 剑指 Offer 54. 二叉搜索树的第 k 大节点

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        int res;
        dfs(root, k, res);
        return res;
    }

    void dfs(TreeNode* node, int& k, int& res) {
        if (k == 0 || node == nullptr) {
            return;
        }
        // 这种结构叫做中序遍历
        dfs(node->right, k, res);
        if(k == 0) {
            return;
        }
        --k;
        if (k == 0) {
            res = node->val;
        }
        dfs(node->left, k, res);
    }
};