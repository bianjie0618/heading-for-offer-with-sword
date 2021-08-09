// 剑指 Offer 03. 数组中重复的数字
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        unordered_map<int, int>::iterator end;
        int result;
        for( auto ele : nums ) {
            if (map.find( ele ) == map.end() ) {
                map[ele] = 1;
            }
            else {
                result = ele;
                break;
            }
        }
        return result;
    }
};