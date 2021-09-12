// 三数之和
// 时间复杂度降到O(n^2)
// 关键一步在于三数之和转变成两数之和
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() == 0) {
            return result;
        }
        sort(nums.begin(), nums.end());
        if (nums.back() < 0) {
            return result;
        }
        int len = nums.size();
        for(int i = 0; i < len - 2; ++i) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i-1]) {
                    continue;
            }
            twoSum(result, nums, i + 1, len - 1, nums[i]);
        }
        return result;
    }

    void twoSum(vector<vector<int>>& result, vector<int>& nums, int left, int right, int value) {
        int start = left;
        int end = right;
        while (start < end) {
            int sum = nums[start] + nums[end] + value;
            if (sum == 0) {
                result.push_back(vector<int>{value, nums[start++], nums[end--]});
            }
            else if (sum < 0) {
                start++;
            }
            else {
                end--;
            }
            while (start > left && start < nums.size() && nums[start - 1] == nums[start]) {
                start++;
            }
            while (end < right && end >= 0 && nums[end] == nums[end + 1]) {
                end--;
            }
        }
    }
};

int main(int argc, char* argv[]) {

    vector<int> arr{-1,0,1,2,-1,-4};
    Solution solution;
    vector<vector<int>> result = solution.threeSum(arr);
    for (auto arr: result) {
        for (auto element : arr) {
            cout << element << ' ';
        }
        cout << '\n';
    }
    return 0;
}