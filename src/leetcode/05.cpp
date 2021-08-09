#include <string>
using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
        int len = s.length();
        string newStr;
        for(int i = 0; i < len; ++i) {
            if (s[i] == ' ') {
                newStr.append("%20");
            }
            else {
                newStr.push_back(s[i]);
            }
        }
        return newStr;
    }
};