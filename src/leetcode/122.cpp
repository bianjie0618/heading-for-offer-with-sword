// 122. 买卖股票的最佳时机 II

// max(prices[n] - prices[0] + profit[0],prices[n] - prices[1] + profit[1],....,prices[n] - prices[n - 1] + profit[n - 1], 0)
// profit[n], profit[0] = 0
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int size = prices.size();
        if (size == 0)
        {
            return 0;
        }
        vector<int> profit(size, 0);
        for (int i = 1; i < size; ++i)
        {
            int maxProfit = 0;
            deque<int> deque;
            for (int k = 0; k < i; ++k) {
                while (!deque.empty() && deque.back() > prices[k]) {
                    deque.pop_back();
                }
                deque.push_back(prices[k]);
            }
            for (int j = 0; j < i; ++j)
            {
                int diff = prices[i] - deque.front();
                maxProfit = max(maxProfit, ((diff) > 0 ? diff : 0) + profit[j]);
                if (!deque.empty() && deque.front() == prices[j]) {
                    deque.pop_front();
                }
            }
            profit[i] = maxProfit;
        }
        return profit.back();
    }
};

int main(int argc, char *argv[])
{

    vector<int> prices{7, 1, 5, 3, 6, 4};
    Solution solution;
    int maxProfit = solution.maxProfit(prices);
    cout << "maxProfit: " << maxProfit << endl;
    return 0;
}
