// 盛水最多的容器
// 本质上是一道双指针的题
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int right = height.size() - 1;
        if (right <= 0) {
            return 0;
        }
        int left = 0;
        int area = 0;
        while (left < right) {
            area = max(area, (right - left)*min(height[left], height[right]));
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return area;
    }
};


/* int main(int argc, char* argv[]) {

    
    return 0;   
} */