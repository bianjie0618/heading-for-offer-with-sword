#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int>::iterator first = nums.begin();
        vector<int>::iterator second = first;
        vector<int>::iterator end = nums.end();
        for(vector<int>::iterator first = nums.begin(); first < end; first++) {
            if ((*first) % 2 == 1) {
                iter_swap(first, second);
                second++;
            }
        }
        return nums;
    }
};