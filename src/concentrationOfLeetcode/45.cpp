// 跳跃游戏
#include <vector>
using namespace std;
// ji
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int len = nums.size();
        vector<int> dp(len);
        for (int i = 0; i < len; ++i) {
            dp[i] = i;
        }
        int maxDistance = 0;
        for (int i = 0; i < len - 1; ++i) {
            int count = nums[i];
            for (int j = i + 1; count > 0; ++j, --count) {
                dp[j] = min(dp[j], dp[j - 1] + 1);
            }
        }
        return dp[len - 1];
    }
};

int main(int argc, char* argv[]) {
    vector<int> arr{2, 1};
    Solution solution;
    int minSteps = solution.jump(arr);
    
    return 0;
}