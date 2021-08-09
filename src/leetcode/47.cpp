// 礼物的最大价值
// 动态规划的使用条件：
// 存在最优子问题、无后向性、子问题的重叠性(这是影响效率的关键因素)
#include <vector>
using namespace std;
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int xLen = grid[0].size();
        int yLen = grid.size();
        for (int i = 1; i < xLen; i++) {
            grid[0][i] += grid[0][i - 1];
        }
        for (int i = 1; i < yLen; ++i) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int y = 1; y < yLen; ++y) {
            for (int x = 1; x < xLen; ++x) {
                grid[y][x] += max(grid[y][x - 1], grid[y- 1][x]);
            }
        }
        return grid[yLen - 1][xLen - 1];
    }
};