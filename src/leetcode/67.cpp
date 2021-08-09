#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int strToInt(string str) {
        int len = str.size();
        int boundary = INT32_MAX / 10;
        int num = 0;
        int isPostive = 1;
        bool isLimit = false;
        int i = 0;
        while (i < len && str[i] == ' '){
            i++;
        }
        if (i < len && str[i] == '-') {
            isPostive = -1;
            i++;
        }
        else if (i < len && str[i] == '+') {
            i++;
        }
        while (i < len) {
            if (str[i] >= '0' && str[i] <= '9') {
                if ( num > boundary || (num == boundary && str[i] > '7') ) {
                    isLimit = true;
                    break;
                }
                num = num * 10 + str[i] - '0';
                i++;
            }
            else {
                break;
            }
            
        }
        if (!isLimit) {
            return isPostive * num;
        }
        else {
            return isPostive == 1 ? INT32_MAX : INT32_MIN;
        }
    }
};

int main(int argc, char* argv[]) {

    Solution solution;
    int result = solution.strToInt("2147483646");
    cout << result << endl;
    return 0;
}