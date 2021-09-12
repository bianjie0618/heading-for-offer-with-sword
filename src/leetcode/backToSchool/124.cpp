
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 深度优先遍历
// 自顶向下的思路，递归处理
#include <unordered_map>
#include <limits>
using namespace std;
class Solution {
 public:
    unordered_map<TreeNode*, int> map;
    int maxSum = numeric_limits<int>::min();
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (map.find(root) != map.end()) {
            return map[root];
        }
        int leftRes = maxPathSum(root->left);
        int rightRes = maxPathSum(root->right);
        int betterPathSum = max(leftRes, rightRes) + root->val;
        if (betterPathSum < 0) {
            betterPathSum = 0;
        }
        betterPathSum += root->val;
        int anotherSum = leftRes + rightRes + root->val;
        map[root] = anotherSum > betterPathSum ? anotherSum : betterPathSum;
        maxSum = max(maxSum, map[root]);
        return betterPathSum;    
    }
};