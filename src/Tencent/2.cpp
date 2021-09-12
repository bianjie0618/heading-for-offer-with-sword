#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/* 2
3
1 1 1
2
1 2 */

void accumulation(vector<int>& arr, int start) {
    int value = arr[start++];
    for (; start < arr.size(); start++) {
        arr[start] += value;
    }
}


int main(int argc, char* argv[]) {
    int T;
    int len = 0;
    cin >> T;
    auto comp = [](int a, int b) {return a > b;};
    for (int i = 0; i < T; ++i) {
        cin >> len;
        vector<int> curArr(len);
        int element;
        for(int j = 0; j < len; ++j) {
            cin >> element;
            curArr[j] = element;
        }
        sort<vector<int>::iterator, decltype(comp)>(curArr.begin(), curArr.end(),comp);
        int sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += curArr[i];
            sum = sum % 1000000007;
            accumulation(curArr, i);
        }
        cout << sum << '\n';
    }
}