#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin >> T;
    int n, w;
    for (int i = 0; i < T; ++i) {
        cin >> n >> w;
        vector<int> curArr(n);
        int resolvedNum = 0;
        int minNum = 0;
        for (int j = 0; j < n; ++j) {
            cin >> curArr[j];
        }
        sort<vector<int>::iterator>(curArr.begin(), curArr.end());
        for(int k = n - 1; k >= 0 && resolvedNum <= n; k--) {
            if (curArr[k] == w) {
                minNum++;
            }
            else if (curArr[k] == 0) {
                continue;
            }
            else {
                int sum = curArr[k];
                for(int a = 0; a < k; a++) {
                    if (curArr[a] != 0 && sum + curArr[a] <= w && (sum + curArr[a]) % 2 == 0) {
                        curArr[a] = 0;
                        resolvedNum++;
                        break;
                    }
                }
                minNum++;
            }
            resolvedNum++;
        }
        cout << minNum << '\n';
    }
}