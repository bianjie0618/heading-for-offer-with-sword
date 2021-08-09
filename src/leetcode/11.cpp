#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int minArray(vector<int>& numbers) {
        if (numbers.size() == 0){
            throw "无效数组"; 
        }
        int end = numbers.size() - 1;
        int start = 0;
        while(start < end) {
            int mid = start + (end - start) / 2;

            if (numbers[mid] > numbers[end]) {
                start = mid + 1;
            }
            else if (numbers[mid] < numbers[end]) {
                end = mid;
            }
            else {
                end--;
            }
        }
        return numbers[start];
    }
};