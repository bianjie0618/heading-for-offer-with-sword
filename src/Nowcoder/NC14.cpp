#include <iostream>
#include <vector>
#include <queue>


using namespace std;
// 二叉树的之字形遍历
// 本质上这就是一个层序遍历，只不过是交替变换方向
// 已通过
 struct TreeNode {	
    int val;
	struct TreeNode *left;
 	struct TreeNode *right;
 };

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        // write code here
        deque<TreeNode*> deque;
        bool isLeftFromRight = true;
        vector<vector<int>> result;
        if(root == nullptr){
            return result;
        }

        deque.push_back(root);
        while(!deque.empty()){
            int currentLayerSize = deque.size();
            vector<int> currentLayer;
            for(int i = 0; i < currentLayerSize; ++i){
                TreeNode* current;
                if(isLeftFromRight){
                    current = deque.front();
                    deque.pop_front();
                    if(current->left != nullptr){
                        deque.push_back(current->left);
                    }
                    if(current->right != nullptr){
                        deque.push_back(current->right);
                    }
                }
                else{
                    current = deque.back();
                    deque.pop_back();
                    if(current->right != nullptr){
                        deque.push_front(current->right);
                    }
                    if(current->left != nullptr){
                        deque.push_front(current->left);
                    }
                }
                currentLayer.push_back(current->val);
            }
            result.push_back(move(currentLayer));
            isLeftFromRight = !isLeftFromRight;
        }
        return result;
    }
};

int main(int argc, char* argv[]){


    return 0;
}