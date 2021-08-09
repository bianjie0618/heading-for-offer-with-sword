/*
    括号序列
*/

#include <unordered_map>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return bool布尔型
     */
    bool isValid(string s) {
        // write code here
        size_t len = s.size();
        if(len == 0){
            return false;
        }
        unordered_map<char, char> leftSign{{'[', ']'}, {'(', ')'}, {'{', '}'}};
        //unordered_set<char> right{']', ')', '}'};
        stack<char> leftStack;
        for(size_t i = 0; i < len; ++i){
            if(leftSign.find(s[i]) != leftSign.end()){
                leftStack.push(s[i]);
            }
            else{
                if(leftStack.size() > 0 && leftSign[leftStack.top()] == s[i]){
                    leftStack.pop();
                }
                else{
                    return false;
                }
            }
        }
        return leftStack.size() == 0;
    }
};