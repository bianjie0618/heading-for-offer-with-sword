#include <string>
#include <vector>
using namespace std;
// 最长回文子串
// 要用到动态规划的思想，关键是要找到 状态转移方程
class Solution {
public:
    int maxLength = 0;
    int getLongestPalindrome(string A, int n) {
        // write code here
        if(A.empty()){
            return 0;
        }
        getLongestPalindromeRecursive(A, 0, A.size() - 1);
        return maxLength;

    }
    
    void getLongestPalindromeRecursive(const string& A, int start, int end){
        if(start > end){
            return;
        }
        int length = end - start + 1;
        int left = start;
        int right = end;
        if(length <= maxLength){
            return;
        }
        while(left < right){
            if(A[left++] != A[right--]){
                break;
            }
        }

        if(left == right){
            maxLength = max(length, maxLength);
            return;
        }
        getLongestPalindromeRecursive(A, start, end - 1);
        getLongestPalindromeRecursive(A, start + 1, end );
    }

    int getLongestPalindromeDp(string A, int n) {
        int length = A.size();
        int maxLength = 0;
        vector<vector<bool>> dp(length, vector<bool>(length, false));
        for(int i = 0; i < length; ++i){
            dp[i][i] = true;
            if(A[i] == A[i + 1]){
                dp[i][i + 1] = true;
                maxLength = max(maxLength, 2);
            }
            if(i - 1 >= 0 && i + 1 <= length && A[i - 1] == A[i + 1]){
                dp[i - 1][i + 1] = true;
                maxLength = max(maxLength, 3);
            }
        }

        for(int j = 2; j < length; ++j){
            for(int k = 0; k <= j - 2; ++k){
                if(dp[k + 1][j - 1] && A[j] == A[k]){
                    dp[k][j] = true;
                    maxLength = max(maxLength, j - k + 1);
                }
            }
        }
        return maxLength;
    }
};