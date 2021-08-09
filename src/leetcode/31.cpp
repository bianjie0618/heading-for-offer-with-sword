// 剑指 Offer 31. 栈的压入、弹出序列
#include <stack>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stack;
        int len1 = pushed.size();
        int len2 = popped.size();
        if (len1 != len2 ) {
            return false;
        }
        if (len1 == 0) {
            return true;
        }
        int i = 0;
        int j = 0;
        
        while ( i < len1 ) {
            stack.push(pushed[i++]);
            while ( !stack.empty() && stack.top() == popped[j]) {
                stack.pop();
                j++;
            }
        }
        return j == len2 ? true : false;
    }
};