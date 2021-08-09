#include <iostream>
#include <vector>
using namespace std;

// 这道题是面试字节的时候遇到的，当时很压抑
// 注意无符号数带来的陷阱，已经碰到数次了。

void solution(int n){
    int total = n * n;
    int bottom = n - 1;
    int ceil = 0;
    int left = 0;
    int right = n - 1;
    int current = 1;
    int i = 0, j = 0;
    vector<vector<int>> arr(n, vector<int>(n));
    while(current <= total){

        for(j = left; j <= right; ++j){
            arr[i][j] = current++;
        }
        j--;
        ceil++;

        for(i = ceil; i <= bottom; ++i){
            arr[i][j] = current++;
        }

        i--;
        right--;

        for(j = right; j >= left; --j){
            arr[i][j] = current++;
        }

        j++;
        bottom--;

        for(i = bottom; i >= ceil; --i){
            arr[i][j] = current++;
        }
        i++;
        left++;
        
    }

    for(const auto row : arr){
        for(const auto element : row){
            cout << element << "\t";
        }
        cout << "\n";
    }

}

int main(int argc, char* argv[]){

    solution(10);
    return 0;
}