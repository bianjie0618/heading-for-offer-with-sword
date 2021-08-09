// 剑指 Offer 32 - III. 从上到下打印二叉树 III
#include <vector>
#include <deque>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> curLine;
        if (root == nullptr) {
            return result;
        }
        deque<TreeNode*> deque;
        deque.push_back(root);
        bool mark = true;
        TreeNode* node = nullptr;
        while(!deque.empty()) {
            int len = deque.size();
            curLine.clear();
            while(len > 0) {
                if (mark) {
                    node = deque.front();
                    deque.pop_front();
                    if(node->left != nullptr) {
                        deque.push_back(node->left);
                    }
                    if (node->right != nullptr) {
                        deque.push_back(node->right);
                    }
                } else {
                    node = deque.back();
                    deque.pop_back();
                    if (node->right != nullptr) {
                        deque.push_front(node->right);
                    }
                    if(node->left != nullptr) {
                        deque.push_front(node->left);
                    }
                }
                len--;
                curLine.push_back(node->val);
            }
            mark = !mark;
            result.push_back(curLine);
        }
        return result;
    }
};