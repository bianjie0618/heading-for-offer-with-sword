// 剑指 Offer 13. 机器人的运动范围
#include <vector>
#include <iostream>
using namespace std;

// 走过的路程一定要做标记
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> mark(m, vector<bool>(n, false));
        return recursiveCount(mark, m, n, k, 0, 0);
    }

    int recursiveCount(vector<vector<bool>>& mark, int m, int n, int k, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || breakDown(x) + breakDown(y) > k || mark[x][y]) {
            return 0;
        }
        mark[x][y] = true;
        int count = 
                     recursiveCount(mark, m, n, k, x + 1, y)
                    + recursiveCount(mark, m, n, k, x, y + 1)
                    + 1;
        return count;
    }

    int breakDown(int m) {
        int res = 0;
        while (m != 0) {
            res += m % 10;
            m = m / 10;
        }
        return res;
    }
};