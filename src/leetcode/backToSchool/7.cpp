// 整数翻转
#include <iostream>
#include <limits>
using namespace std;

// 此题虽然简单，但是考察的是数学推到能力

class Solution {
public:
    int reverse(int x) {
        int newValue = 0;
        int upperLimit = numeric_limits<int>::max() / 10;
        int lowerLimit = numeric_limits<int>::min() / 10;
        while (x != 0) {
            int remainder = (x % 10);
            x /= 10;
            if (newValue < lowerLimit || newValue > upperLimit) {
                return 0;
            }
            newValue = newValue * 10 + remainder;
        }
        return newValue;
    }
};

int main() {

    int num = -16;
    constexpr int upperLimit = numeric_limits<int>::max();
    cout << num % 10 << "\n";
    return 0;
}