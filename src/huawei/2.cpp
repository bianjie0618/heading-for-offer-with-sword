#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>>& arr) {
    int rows = arr.size();
    if (rows == 0) {
        return 0;
    }
    int columns = arr[0].size();
    vector<vector<int>> dp1(rows, vector<int>(columns, 0));
    vector<vector<int>> dp2(rows, vector<int>(columns, 0));
    vector<vector<int>> dp3(rows, vector<int>(columns, 0));
    dp1[0][0] = 0;
    for (int k = 0; k < rows; ++k) {
        for (int i = 0; i < columns - 1; ++i) {
            int limit = arr[k][i];
            for(int j = i + 1; j < columns && j <= i + limit; j++) {
                if (arr[k][j] == 0) {
                    continue;
                }
                else {
                    if (dp1[k][j] == 0) {
                        dp1[k][j] = dp1[k][i] + 1;
                    }
                }
            }
        }
    }

    for (int k = 0; k < columns; ++k) {
        for (int i = 0; i < rows - 1; ++i) {
            int limit = arr[i][0];
            for(int j = i + 1; j < rows && j <= i + limit; j++) {
                if (arr[j][0] == 0) {
                    continue;
                }
                else {
                    if (dp2[j][0] == 0) {
                        dp2[j][0] = dp2[i][0] + 1;
                    }
                }
            }
        }
    }

    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < columns; ++j) {
            if (arr[i][j] == 0) {
                continue;
            }
            int route1 = dp1[0][j] + dp2[i][j];
            int route2 = dp2[i][0] + dp1[i][j];
            dp3[i][j] = min(route1, route2);
        }
    }
}