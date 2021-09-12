#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct BinaryTree{
    int number;
    int val;
    int sumBelow;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int num, int val): number(num), val(val), left(nullptr), right(nullptr), sumBelow(0) {}
};

class Solution {
    int maxDiff = 0;
    int theNumber = 0;
public:
    int solution(BinaryTree* root) {
        recursionForSum(root);
        int rightSum = root->val + (root->right == nullptr ? 0 : root->right->sumBelow);
        int leftSum = root->val + (root->left == nullptr ? 0 : root->left->sumBelow);
        recursionForDiff(root->left, rightSum);
        recursionForDiff(root->right, leftSum);
        return theNumber;
    }

    void recursionForDiff(BinaryTree* root, int sumAbove) {
        if (root == nullptr) {
            return;
        }
        int currentDiff = abs(root->sumBelow - sumAbove);
        if (currentDiff > maxDiff) {
            maxDiff = currentDiff;
            theNumber = root->number;
        }
        else if (currentDiff == maxDiff && root->number < theNumber) {
            theNumber = root->number;
        }
        int rightSum = root->val + (root->right == nullptr ? 0 : root->right->sumBelow);
        int leftSum = root->val + (root->left == nullptr ? 0 : root->left->sumBelow);
        recursionForDiff(root->left, sumAbove + rightSum);
        recursionForDiff(root->right, sumAbove + leftSum);
    }

    int recursionForSum(BinaryTree* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftSum = recursionForSum(root->left);
        int rightSum = recursionForSum(root->right);
        root->sumBelow = root->val + leftSum + rightSum;
        return root->sumBelow;
    }
};

int main(int argc, char* argv[]) {
    int nodeCount;
    cin >> nodeCount;
    vector<int> weight(nodeCount);
    for (int i = 0; i < nodeCount; ++i) {
        cin >> weight[i];
    }
    unordered_map<int, BinaryTree*> map;
    BinaryTree* root = new BinaryTree(0, weight[0]);
    map[0] = root;
    for (int i = 0; i < nodeCount - 1; ++i) {
        int father, child;
        cin >> father >> child;
        BinaryTree* current = new BinaryTree(child, weight[child]);
        BinaryTree* fatherPtr = map[father];
        if (fatherPtr->left == nullptr) {
            fatherPtr->left = current;
        }
        else {
            fatherPtr->right = current;
        }
        map[child] = current;
    }
    Solution solution;
    int result = solution.solution(map[0]);
    cout << result << '\n';
    return 0;
}