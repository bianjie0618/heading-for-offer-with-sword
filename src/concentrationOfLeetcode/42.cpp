// 接雨水
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = 0;
        int len = height.size();
        int currentWater = 0;
        while (left < len - 1 && height[left] <= height[left + 1]) {
            left++;
        }
        right = left;
        while (right < len - 1)
        {
            while(right < len - 1 && height[right] >= height[right + 1]) {
                right++;
            }
            while (right < len - 1 && height[right] <= height[right + 1]) {
                right ++;
            }
            currentWater += areaBetweenGroove(height, left, right);
            left = right;
        }
        int highLevelValue = 0;
        if (currentWater > 0) {
            highLevelValue = trap(height);
        }
        return currentWater + highLevelValue;
    }
    int areaBetweenGroove(vector<int>& height, int start, int end) {
        int smallerVal = min(height[start], height[end]);
        int areaOfPillar = 0;
        for(int i = start + 1; i < end; ++i) {
            areaOfPillar += height[i] < smallerVal ? height[i] : smallerVal;
            height[i] = height[i] > smallerVal ? height[i] : smallerVal;;
        }
        int areaOfWater = (end - start - 1) * smallerVal - areaOfPillar;
        return areaOfWater > 0 ? areaOfWater : 0;
    }
};