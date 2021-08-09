// 剑指 Offer 32 - I. 从上到下打印二叉树
#include <queue>
#include <vector>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        // 层序遍历
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty())
        {
            int len = queue.size();
            while(len > 0) {
                TreeNode* cur = queue.front();
                queue.pop();
                result.push_back(cur->val);
                len--;
                if (cur->left != nullptr) {
                    queue.push(cur->left);
                }
                if (cur->right != nullptr) {
                    queue.push((cur->right));
                }
            }
        }
        return result;
    }
};