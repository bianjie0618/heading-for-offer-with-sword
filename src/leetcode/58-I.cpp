#include <string>
using namespace std;
// 剑指 Offer 58 - I. 翻转单词顺序 - 解决方案
// 双指针思路
class Solution {
public:
    string reverseWords(string s) {
        int right = s.length() - 1;
        int left = right;
        string newStr;
        while(left >= 0) {
            while (left >= 0 && s[left] == ' ') {
                left--;
            }
            right = left;
            while(left >= 0 && s[left] != ' ') {
                left--;
            }
            if (left < right && newStr.size() > 0) {
                newStr.append(" ");
            }
            newStr.append(s, left + 1, right - left);
        }
        return newStr;
    }
};