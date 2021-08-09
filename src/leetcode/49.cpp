// 剑指 Offer 49. 丑数 - 解决方案
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n < 1) {
            return 0;
        }
        vector<int> arr(n);
        arr[0] = 1;
        int a_2 = 0;
        int b_3 = 0;
        int c_5 = 0;
        for(int i = 1; i < n; ++i) {
            arr[i] = min(min(arr[a_2]*2, arr[b_3]*3), arr[c_5]*5);
            if (arr[i] == arr[a_2]*2) {
                a_2++;
            }
            if (arr[i] == arr[b_3]*3) {
                b_3++;
            }
            if (arr[i] == arr[c_5]*5) {
                c_5++;
            }
        }
        return arr[n-1];
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    int result = solution.nthUglyNumber(10);
    cout << result << endl;
    return 0;
}