#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    vector<vector<int>> augment(vector<vector<int>>& sourceImg, int K) {
        int sourceLen = sourceImg.size();
        vector<vector<int>> res(sourceLen * K, vector<int>(sourceLen * K));
        if (sourceLen == 0) {
            return res;
        }
        for (int i = 0; i < sourceLen; ++i) {
            for (int j = 0; j < sourceLen; ++j) {
                int startRowNum = i * K;
                int endRowNum = startRowNum + K;
                int startColumnNum = j * K;
                int endColumnNum = startColumnNum + K;
                for (int m = startRowNum; m < endRowNum; ++m) {
                    for (int n = startColumnNum; n < endColumnNum; ++n) {
                        res[m][n] = sourceImg[i][j];
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    int N, K;
    cin >> N >> K;
    vector<vector<int>> sourceImg(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> sourceImg[i][j];
        }
    }
    vector<vector<int>> augmentedImg = solution.augment(sourceImg, K);
    for (auto& row : augmentedImg) {
        for (auto element : row) {
            cout << element << ' ';
        }
        cout << '\n';
    }
    return 0;
}