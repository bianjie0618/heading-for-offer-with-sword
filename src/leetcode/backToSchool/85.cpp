// 最大矩形问题

// 方法一：暴力解法
#include <vector>
#include <stack>
using namespace std;

/* class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) {
            return 0;
        }
        int colums = matrix[0].size();
        vector<vector<int>> statistics(rows, vector<int>(colums + 1, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < colums; ++j) {
                if (matrix[i][j]) {
                    statistics[i][j+1] = statistics[i][j] + 1;
                }
            }
        }
        int area = 0;
        for( int i = 0; i < rows; ++i) {
            for (int j = 0; j < colums; ++j) {
                int width = colums;
                for (int k = i; k >= 0; --k) {
                    int height = i - k + 1;
                    width = min(width, statistics[k][j+1]);
                    area = max(area, width * height);
                }
            }
        }
        return area;
    }
}; */


// 方法二：利用单调栈去求解
// 需要准备好每一行 左边连续为 1 的个数

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) {
            return 0;
        }
        int colums = matrix[0].size();
        vector<vector<int>> records(rows, vector<int>(colums, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < colums; ++j) {
                if (matrix[i][j]) {
                    records[i][j] = (j == 0 ? 0 : records[i][j - 1]) + 1;
                }
            }
        }

        int area = 0;
        // 用到了单调栈的思想
        // 后一个受制于前一个的大小的影响
        for (int j = 0; j < colums; ++j) {
            vector<int> up(rows, 0), down(rows, 0);
            stack<int> stk;
            for (int i = 0; i < rows; ++i) {
                while (!stk.empty() && records[stk.top()][j] >= records[i][j]) {
                    stk.pop();
                }
                up[i] = stk.empty() ? -1 : stk.top();
                stk.push(i);
            }

            while (!stk.empty()) {
                stk.pop();
            }
            for (int i = rows - 1; i >= 0; --i) {
                while (!stk.empty() && records[stk.top()][j] >= records[i][j]) {
                    stk.pop();
                }
                down[i] = stk.empty() ? rows : stk.top();
                stk.push(i);
            }

            for (int i = 0; i < rows; ++i) {
                int height = records[i][j];
                int width = down[i] - up[i] - 1;
                area = max(area, height * width);
            }
        }
        return area;
    }
};
