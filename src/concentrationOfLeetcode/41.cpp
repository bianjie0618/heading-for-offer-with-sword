// 41. 缺失的第一个正数
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

// 1. 找到数组中最小的正数
// 2. 遍历数组，把数字放到正确的位置，a[i] = i+1
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        auto comp = [](int a, int b) {
            if (a > 0 && b > 0) {
                return a < b;
            }
            else if (a <= 0) {
                return false;
            }
            else {
                return true;
            }
        };
        int len = nums.size();
        int minimal = *min_element<vector<int>::iterator, decltype(comp)>(nums.begin(), nums.end(), comp);
        for(int i = 0; i < len; ++i) {
            while (nums[i] > 0 && nums[i] - minimal < len && nums[i] - minimal != i && nums[nums[i] - minimal] != nums[i]) {
                swap(nums[i], nums[nums[i] - minimal]);
            }
        }

        for (int i = 0; i < len; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return len + 1;
    }
};

int main(int argc, char* argv[]) {
    vector<int> arr{3,4,-1,1};
    Solution solution;
    int min_number = solution.firstMissingPositive(arr);
    cout << "min_number: " << min_number << endl;
    return 0;
}