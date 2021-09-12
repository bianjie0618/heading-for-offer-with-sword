// 求取最大公约数
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int isGcdEqualsOne(int a, int b) {
    if (a > b) {
        swap(a, b); // 保证a <= b
    }
    for (int i = 2; i <= a; ++i) {
        if (a % i == 0 && b % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(int N) {
    int limit = (int)sqrt(N);
    int num = 0;
    for (int i = 1; i <= limit; ++i) {
        if (N % i == 0 && isGcdEqualsOne(i, N / i)) {
            num++;
        }
    }
    return num;
}

int main(int argc, char* argv[]) {

    int T;
    cin >> T;
    vector<int> data(T);
    for (int i = 0; i < T; ++i) {
        cin >> data[i];
    }
    for (auto ele : data) {
        cout << solution(ele) << '\n';
    }
    return 0;
}