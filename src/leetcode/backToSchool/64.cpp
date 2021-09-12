// 最小路径和
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) {
            return 0;
        }
        int columns = grid[0].size();
        vector<int>* dp1 = new vector<int>(columns);
        (*dp1)[0] = grid[0][0];
        vector<int>* dp2 = new vector<int>(columns);
        for (int j = 1; j < columns; ++j) {
            (*dp1)[j] = grid[0][j] + (*dp1)[j-1];
        }
        for (int i = 1; i < rows; ++i) {
            (*dp2)[0] = (*dp1)[0] + grid[i][0];
            for (int j = 1; j < columns; ++j) {
                (*dp2)[j] = min((*dp2)[j-1] + grid[i][j], (*dp1)[j] + grid[i][j]);
            }
            swap(dp1, dp2);
        }
        return (*dp1)[columns - 1];
    }
};