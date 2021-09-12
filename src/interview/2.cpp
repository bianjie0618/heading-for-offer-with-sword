// NC44 通配符匹配
// 这道题细节非常多；经过不断调试，我终于做出来了，哈哈哈
#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char* first = s;
        const char* second =  p;
        while (*first != 0 && *second != 0) {
            if(*second != '*' && *second != '?' &&*first != *second) {
                return false;
            }
            else if (*second != '*' && *second != '?' && *first == *second) {
                first++;
                second++;
            }
            else {
                if (*second == '?') {
                    second++;
                    first++;
                }
                else {
                    int questionCount = 0;
                    while (*(second + 1) != 0 && (*(second + 1) == '*' || *(second + 1) == '?')) {
                        second++;
                        if (*second == '?') {
                            questionCount++;
                        }
                    }
                    char nextChar = *(second + 1);
                    for (int i = 0; i < questionCount; ++i) {
                        if (*(first+i) == 0) {
                            return false;
                        }
                    }
                    if (isMatch(first + questionCount, second + 1)) {
                        return true;
                    }
                    while(*first != 0 && *second != 0) {
                        while (*first != 0 && *second != 0 && (*first != nextChar || questionCount > 0)) {
                            first++;
                            questionCount--;
                        }
                        bool result = isMatch(first, second+1);
                        if (result)
                            return true;
                        if (*first != 0)
                            first++;
                    }
                    
                }
            }
            
        }
        while (*second == '*' && *(second + 1) != 0) {
            second++;
        }
        if (*first == 0 && *second == 0 || *second == '*' && *(second + 1) == 0) {
            return true;
        }
        
        return false;
        
    }
};

int main(int argc, char* argv[]) {

    char* s = "a@c";
    char* p = "***a***?*****c***";
    Solution solution;
    bool result = solution.isMatch(s, p);
    cout << "result = " << result << endl;
    return 0;
}