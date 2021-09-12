// 柱状图中的最大矩形面积
#include <vector>
#include <stack>
using namespace std;

/**
 * 单调栈 （Monotone Stack)
 * 单调栈是栈的应用场景
 * 栈内元素维持了[单调性]的应用场景
 * 1. 单调递增（不减）栈可以找到左边第一个比当前出栈元素小（包含等于）的元素
 * 2. 单调递减栈（不增）可以找到左边第一个比当前出栈元素大（包含等于）的元素
 * 应用单调栈的关键是找出处理问题符合[后进先出]的顺序；FILO
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 哨兵思想，稍后再说
        int len = heights.size();
        vector<int> newHeights(len + 2, 0);
        for(int i = 0; i < len; i++) {
            newHeights[i + 1] = heights[i];
        }
        len += 2;
        int area = 0;
        stack<int> stack;
        stack.push(0);
        for(int i = 1; i < len; ++i) {
            while(newHeights[i] < newHeights[stack.top()]) {
                int height = newHeights[stack.top()];
                stack.pop();
                while(newHeights[stack.top()] == height) {
                    stack.pop();
                }
                int width = stack.empty() ? i : i - stack.top() - 1;
                area = max(area, height * width);                
            }
            stack.push(i);
        }
        return area;
    }
};