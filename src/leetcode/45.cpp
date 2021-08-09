// 剑指 Offer 45. 把数组排成最小的数

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool compare(int lhs, int rhs) {
       string permulation1 = to_string(lhs) + to_string(rhs); 
       string permulation2 = to_string(rhs) + to_string(lhs); 
       if (permulation1 < permulation2){
           return true;
       }
       else {
           return false;
       }
}
class Solution {
public:
    string minNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        string result;
        for(int ele : nums) {
            result += to_string(ele);
        }
        return result;
    }
};

int main(int argc, char* argv[]) {

    vector<int> test {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,300,0,0,1,0,10,0,0,0,22,0,0,8,0,0,81,0,0,0,71,0};
    Solution solution;
    string num = solution.minNumber(test);
    cout << "合成的数字是：" << num << endl;
    return 0;
}
