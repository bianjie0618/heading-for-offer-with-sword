// 剑指 Offer 10 - II. 青蛙跳台阶问题
// 本质上和斐波那契数列问题没什么区别

#include <array>
using namespace std;
class Solution {
public:
    int numWays(int n) {
        array<int, 2> arr;
        arr[0] = 1;
        arr[1] = 1;
        if (n < 2) {
            return arr[n];
        }
        for(int i = 2; i <= n; ++i) {
            int tmpt = (arr[0] + arr[1]) % 1000000007;
            arr[0] = arr[1];
            arr[1] = tmpt;
        }
        return arr[1];
    }
};