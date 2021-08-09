// 剑指 Offer 46. 把数字翻译成字符串
#include <stack>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    int translateNum(int num) {
        if (num == 0) {
            return 1;
        }
        stack<int> stack;
        while(num != 0) {
            int remainder = num % 10;
            stack.push(remainder);
            num /= 10;
        }
        vector<int> dp(stack.size() + 1);
        dp[0] = 1;
        dp[1] = 1;
        int index = 2;
        int len = dp.size();
        int currentNum;
        int preNum = stack.top();
        stack.pop();
        while (index < len) {
            currentNum = stack.top();
            stack.pop();
            int composedNum = preNum * 10 + currentNum;
            preNum = currentNum;
            dp[index] = dp[index - 1];
            if (composedNum >= 10 && composedNum < 26) {
                dp[index] += dp[index - 2];
            }
            index++;
        }
        return dp[len - 1];
    }
};

int main(int argc, char* argv[]) {

    string a(to_string(1010));
    for (auto ele : a) {
        cout << ele << ' ' ;
    }
    cout << endl;
    return 0;
}