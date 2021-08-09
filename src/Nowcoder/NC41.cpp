#include <vector>
#include <unordered_map>
using namespace std;// namespace name


class Solution {
public:
    /**
     * 
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) {
        // write code here
        size_t maxLength = 0;
        size_t len = arr.size();
        if(len == 0){
            return 0;
        }
        size_t left = 0;
        size_t right = 0;
        // 用map进行存储，存储前先查询map中有没有已经存在当前元素，如果有，移动左边的指针，直到把左指针放在重复元素中的前面的一个元素索引的下一个位置；
        // 如果没有重复，则可以直接存放到map中
        // 总体上利用了 map 加上 双指针 的思路，这其实是一道滑动窗口的题。
        // 时间复杂度，O(n)
        // 空间复杂度最坏情况就是O(n), 因为要利用map存放数组中的元素和下标
        unordered_map<int, size_t> map;
        while(right < len){
            
            if(map.find(arr[right]) != map.end()){
                maxLength = max(right - left, maxLength);
                size_t previous = map[arr[right]];
                while(left <= previous){
                    map.erase(arr[left++]);
                }
            }
            map[arr[right]] = right;
            right++;
        }
        return max(right - left, maxLength);
    }
};