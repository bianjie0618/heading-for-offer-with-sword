#include <vector>
#include <queue>
using namespace std;
//Definition for a binary tree node.
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
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) {
            int len = queue.size();
            curLine.clear();
            while (len > 0) {
                TreeNode* currentNode = queue.front();
                queue.pop();
                len--;
                curLine.push_back(currentNode->val);
                if (currentNode->left != nullptr) {
                    queue.push(currentNode->left);
                }
                if (currentNode->right != nullptr) {
                    queue.push(currentNode->right);
                }
            }
            result.push_back(curLine);
        }
        return result;
    }
};