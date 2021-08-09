#include <vector>
#include <iostream>
using namespace std;
// 剑指 Offer 53 - I. 在排序数组中查找数字 I
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch( nums, 0, nums.size() - 1, target ) - binarySearch( nums, 0, nums.size() - 1, target - 1 );
    }

    int binarySearch(const vector<int>& arr, int start, int end, int target) {
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] <= target) {
                start = mid + 1;
            }
            else { // (arr[mid] > target)
                end = mid - 1;
            }
        }
        return start;
    }
};

int main(int argc, char* argv[]) {

    vector<int> test {2,2};
    Solution solution;
    int num = solution.search(test, 2);
    cout << "Number: " << num << endl;
    return 0;
}