#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class Solution{
    int minValue;
public:
    int solution(string str, int N) {
        minValue = numeric_limits<int>::max();
    }

    int recursive(string str, int reversionNum, int len) {
        char start = str[0];
        int i = 1;
        for (; i < len; ++i) {
            if (str[i] < str[i - 1]) {
                break;
            }
        }
        if (i == len) {
            return reversionNum;
        }
    }

    void reversion (string& str, int start, int end) {
        while (start <end) {
            swap(str[start], str[end]);
        }
    }

};

int main(int argc, char* argv[]) {
    Solution solution;
    int N, Q;
    cin >> N >> Q;
    vector<string> data(Q);
    for (int i = 0; i < Q; i++) {
        string tmpt;
        cin >> tmpt;
        data.push_back(tmpt);
    }
    for (auto& str: data) {
        cout << solution.solution(str, N) << '\n';
    }
    return 0;
}
