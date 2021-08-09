#include <vector>
#include <iostream>
using namespace std;
// 剑指 Offer 29. 顺时针打印矩阵
//  1   2   3   4
//  5   6   7   8
//  9   10  11  12
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.size() == 0) {
            return result; // 返回的是右值
        }
        
        int upperBound = 0;
        int lowerBound = matrix.size() - 1;
        int leftBound = 0;
        int rightBound = matrix[0].size() - 1;

        while(true) {
            
            if (upperBound > lowerBound || leftBound > rightBound) {
                break;
            }
            // 从 左 到 右
            for(int i = leftBound; i <= rightBound; ++i) {
                result.push_back(matrix[upperBound][i]);
            }
            upperBound++;

            if (upperBound > lowerBound || leftBound > rightBound) {
                break;
            }
            // 从 上 到 下
            for(int j = upperBound; j <= lowerBound; ++j) {
                result.push_back(matrix[j][rightBound]);
            }
            rightBound--;

            if (upperBound > lowerBound || leftBound > rightBound) {
                break;
            }
            // 从 右 到 左
            for(int i = rightBound; i >= leftBound; --i) {
                result.push_back(matrix[lowerBound][i]);
            }
            lowerBound--;

            if (upperBound > lowerBound || leftBound > rightBound) {
                break;
            }
            // 从 下 到 上
            for(int j = lowerBound; j >= upperBound; --j) {
                result.push_back(matrix[j][leftBound]);
            }
            leftBound++;
        }
        return result;
    }
};