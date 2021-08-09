/**
 * 一个整数可以被分解为多个整数的乘积，例如，6 可以分解为 2x3。请使用递归编程的方法，
 * 为给定的整数 n，找到所有可能的分解（1 在解中最多只能出现 1 次）。
 * 例如，输入 8，输出是可以是 1x8, 8x1, 2x4, 4x2, 1x2x2x2, 1x2x4, ……
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    vector<vector<int>> printArr;
    int originVal;
public:
    void solution(int num) {
        vector<int> initval;
        originVal = num;
        recursive(false, num, initval);
        this->pint();
    }

private:
    void recursive(bool hasOne, int num, vector<int>& arr) {
        if (num == 1) {
            // 放进打印队列
            if (arr.size() == 1 || !hasOne) {
                arr.push_back(1);
            }
            printArr.push_back(arr);
            return;
        }
        int i = 2;
        for(; i <= num; i++) {
            vector<int> unknownIfExistingOne = arr;
            if (num % i == 0) {
                if (!hasOne) {
                    vector<int> addOne = arr;
                    addOne.push_back(1);
                    addOne.push_back(i);
                    recursive(true, num / i, addOne);
                }
                unknownIfExistingOne.push_back(i);
                recursive(hasOne, num / i, unknownIfExistingOne);     // 保持原来的特定特性不丢
            }
            else
                continue;
        }
    }

    void pint() {
        for(auto arr: printArr) {
            int len = arr.size() - 1;
            for(int i = 0; i < len; ++i) {
                cout << arr[i] << " x ";
            }
            cout << arr[len] << endl;
        }
        cout << "共计 " << printArr.size() << " 种分解方式." << endl;
    }

};

int main (int argc, char* argv[]) {
    Solution sol;
    sol.solution(8);
    return 0;
}