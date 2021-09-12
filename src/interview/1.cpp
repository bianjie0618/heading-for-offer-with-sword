// leetcode 122. 买卖股票的最佳时机 II
#include <vector>
using namespace std;
struct result {
    int lirun;
    int Price;
    result(int lirun, int maxPrice): lirun(lirun), Price(maxPrice) {}
};
result* solution(vector<int>& arr, int end) {
    if (end == 0) {
        return new result(0, arr[0]);
    }
    result* ptr = solution(arr, end - 1);
    if (arr[end] <= ptr->Price) {
        return ptr;
    }
    else {
        return new result(ptr->lirun + arr[end] - ptr->Price, arr[end]);
    }
}