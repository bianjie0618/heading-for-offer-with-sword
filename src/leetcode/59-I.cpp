#include <vector>
#include <list>
using namespace std;

// 剑指 Offer 59 - I. 滑动窗口的最大值 - 解决方案

// 通过队列 的 先进先出 思想，保证每个元素只进出队列一次
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int> bidirectionalList;
        vector<int> result;
        int left = 1 - k;
        int right = 0;
        int len = nums.size();
        for ( ; right < len; right++, left++ ) {
            if (left > 0 && nums[left - 1] == bidirectionalList.front() ) {
                bidirectionalList.pop_front();
            }
            while ( !bidirectionalList.empty() && bidirectionalList.back() < nums[right] ) {
                bidirectionalList.pop_back();
            }
            bidirectionalList.push_back(nums[right]);
            if( left >= 0 ) {
                result.push_back( bidirectionalList.front() );
            }
        }
        return result;
    }
};