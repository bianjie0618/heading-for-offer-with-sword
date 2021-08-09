#include <vector>
using namespace std;
// 剑指 Offer 39. 数组中出现次数超过一半的数字
// 耗死 少数minority 算法，也称 摩尔投票
// 时间复杂度 O(n)  空间复杂度 O(1) 关键在于空间复杂度很优秀
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() < 0) {
            throw "不允许空数组";
        }
        int cur = nums[0];
        int count = 1;
        int len = nums.size();
        for(int i = 1; i < len; i++) {
            if (nums[i] != cur) {
                count--;
            }
            else {
                count++;
            }
            if (count == 0) {
                cur = nums[i];
                count++;
            }
        }
        return cur;
    }
};