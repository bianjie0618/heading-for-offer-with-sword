#include <vector>
#include <iostream>
class Solution {

public:
    int climbStairs(int n) {
        std::vector<int> arr(n + 1, 0);
        arr[1] = 1;
        arr[0] = 1;
        for(int i = 2; i <= n; ++i) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr[n];
        
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    std::cout << solution.climbStairs(2) << std::endl;
}