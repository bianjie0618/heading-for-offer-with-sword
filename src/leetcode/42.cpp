// 剑指 Offer 42. 连续子数组的最大和 - 解决方案

// 存在最优子结构
// 无后向性
// 子问题重叠性
#include <iostream>
#include <vector>
using namespace std;
class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int len = nums.size();
        dp[0] = nums[0];
        for (int i = 1; i < len; ++i) {
            dp[i] = dp[i - 1] > 0 ? dp[i - 1] + nums[i] : nums[i];
        }
        int max = dp[0];
        for(int element : dp) {
            max = max < element ? element : max;
        }
        return max;
    }
};


class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        for (int i = 1; i < len; ++i) {
            nums[i] = nums[i - 1] > 0 ? nums[i - 1] + nums[i] : nums[i];
        }
        int max = nums[0];
        for(int element : nums) {
            max = max < element ? element : max;
        }
        return max;
    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int curSum = 0;
        int maxSum = nums[0];
        int len = nums.size();
        while( right < len ) {
            if (curSum <= 0) {
                left = right + 1;
                curSum = 0;
            }
            curSum += nums[right];
            maxSum = maxSum < curSum ? curSum : maxSum;
            right++;
        }
        return maxSum;
    }
};