#include <vector>
#include <iostream>
using namespace std;
// 剑指 Offer 04. 二维数组中的查找
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int rows = matrix.size();
        int columns = matrix[0].size();
        if ( target < matrix[0][0] || target > matrix[rows - 1][columns - 1]) {
            return false;
        }
        int xmid = 0;
        int ymid = rows - 1;
        while (xmid < columns && ymid >= 0) {
            if (matrix[ymid][xmid] == target) {
                return true;
            }
            else if (matrix[ymid][xmid] < target) {
                xmid += 1;
            }
            else {
                ymid -= 1;
            }
        }
        return false;
    }

};
int main() {
    Solution solution;
    vector<vector<int>> arr{{-1, 3}};
    cout <<  "运算结果是：" <<solution.findNumberIn2DArray(arr, 3) << endl;
    // std::cout << "Hello World!\n";
}