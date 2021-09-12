// 不同路径II
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int columns = obstacleGrid[0].size();
        if (rows == 0) {
            return 0;
        }
        vector<vector<int>> dp(rows, vector<int>(columns, 1));
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        for (int j = 1; j < columns; ++j) {
            if (obstacleGrid[0][j] == 1) {
                dp[0][j] = 0;
            }
            else {
                dp[0][j] = dp[0][j-1];
            }
        }
        for (int i = 1; i < rows; ++i) {
            if (obstacleGrid[i][0] == 1) {
                dp[i][0] = 0;
            }
            else {
                dp[i][0] = dp[i-1][0];
            }
        }
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < columns; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }
            }
        }
        return dp[rows-1][columns-1];
    }
};
