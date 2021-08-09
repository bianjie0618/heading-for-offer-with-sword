#include <vector>
#include <iostream>
using namespace std;
// 剑指 Offer 57 - II. 和为 s 的连续正数序列
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int left = 1;
        int right = 2;
        vector<vector<int>> result;
        while (left < right) {
            while( sequentialSum(left, right) < target ) {
                right++;
            }
            if ( sequentialSum(left, right) == target) {
                vector<int> cur;
                for(int i = left; i <= right; ++i) {
                    cur.push_back(i);
                }
                result.push_back(cur);
                left++;
                right++;
            }
            while( sequentialSum(left, right) > target ) {
                left++;
            }
        }
        return result;
    }

    int sequentialSum(int start, int end) {
        int sum  = (start + end) * (end - start + 1) / 2;
        return sum;
    }
};