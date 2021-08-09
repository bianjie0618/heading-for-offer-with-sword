// 剑指 Offer 63. 股票的最大利润
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int pre = prices[0];
        int cur = prices[1];
        prices[0] = 0;
        int len = prices.size();
        for (int i = 1; i < len; ++i) {
            cur = prices[i];
            int curProfit = cur - pre + prices[i - 1];
            pre = cur;
            prices[i] = curProfit > 0 ? curProfit : 0;
        }
        int maxProfit = 0;
        for (auto ele : prices) {
            maxProfit = maxProfit < ele ? ele : maxProfit;
        }
        return maxProfit;
    }
};