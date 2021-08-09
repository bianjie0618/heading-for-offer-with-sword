#include <string>
#include <iostream>
#include <array>
using namespace std;
// 剑指 Offer 50. 第一个只出现一次的字符
// 此题本质上还是 哈希算法
class Solution {
public:
    char firstUniqChar(string s) {
        array<int, 26> arr;
        arr.fill(0);
        for(auto element: s) {
            arr[element - 'a']++;
        }
        for(auto ele: s) {
            if ( arr[ele - 'a'] == 1 ) {
                return ele;
            }
        }
        return ' ';
    }
};