// 剑指 Offer 53 - II. 0～n-1中缺失的数字 - 解决方案
#include <vector>
#include <iostream>
using namespace std;

// ** 二分查找的 花式应用
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == mid) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return start;
    }
};