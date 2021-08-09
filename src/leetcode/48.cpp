// 剑指 Offer 48. 最长不含重复字符的子字符串
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        unordered_map<char, int> map;
        int len = s.size();
        int maxLen = 0;
        while( right < len ) {
            if ( map.count(s[right]) > 0 ) {
                maxLen = right - left > maxLen ? right - left : maxLen;
                while ( left <= map[s[right]] ) {
                    map.erase(s[left++]);
                }
            } 
            map[s[right++]] = right;
        }
        return right - left > maxLen ? right - left : maxLen;;
    }
};